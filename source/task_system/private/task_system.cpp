#include "precompiled_header.h"

#include "task_system.h"

namespace TaskSystem {

TaskSystem::~TaskSystem() { Join(); }

void TaskSystem::Initialize(Task* begin, Task* end) {
  for (Task* i = begin; i < end; ++i) {
    task_queue_.emplace(*i);
  }

  thread_pool_.Initialize(&TaskThreadEntrypointStatic,
                          static_cast<void*>(this));
}

void TaskSystem::Abort() {
  {
    std::lock_guard lock(state_mutex_);
    if (is_shutting_down_) {
      return;
    }
    is_shutting_down_ = true;
  }

  wake_signal_.notify_all();
}

void TaskSystem::Join() { thread_pool_.Join(); }

void TaskSystem::AddTask(const Task& task) {
  {
    std::lock_guard lock(state_mutex_);
    task_queue_.push(task);
  }
  wake_signal_.notify_one();
}

void TaskSystem::TaskThreadEntrypointStatic(Threading::Thread* thread,
                                            void* user_data) {
  auto* task_system = static_cast<TaskSystem*>(user_data);
  task_system->TaskThreadEntrypoint(thread);
}

void TaskSystem::TaskThreadEntrypoint(Threading::Thread*) { TaskLoop(); }

void TaskSystem::TaskLoop() {
  std::unique_lock lock(state_mutex_);
  while (true) {
    if (is_shutting_down_) {
      return;
    }

    if (!task_queue_.empty()) {
      Task task = task_queue_.front();
      task_queue_.pop();
      lock.unlock();
      task.entrypoint(this, task.user_data);
      lock.lock();
      continue;
    }

    if (idle_threads_ + 1 == thread_pool_.GetThreadCount()) {
      is_shutting_down_ = true;
      lock.unlock();
      wake_signal_.notify_all();
      return;
    }

    ++idle_threads_;
    wake_signal_.wait(lock);
    --idle_threads_;
  }
}

}  // namespace TaskSystem

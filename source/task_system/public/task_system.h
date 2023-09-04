#pragma once

#include "task.h"
#include "thread.h"
#include "thread_pool.h"

namespace BoolkaEngine::TaskSystem {
class TaskSystem {
 public:
  TaskSystem() = default;
  ~TaskSystem();

  TaskSystem(const TaskSystem&) = delete;
  TaskSystem(TaskSystem&&) = delete;
  TaskSystem& operator=(const TaskSystem&) = delete;
  TaskSystem& operator=(TaskSystem&&) = delete;

  void Initialize(Task* begin, Task* end);
  void Abort();
  void Join();

  void AddTask(const Task& task);

 private:
  static void TaskThreadEntrypointStatic(Threading::Thread* thread,
                                         void* user_data);
  void TaskThreadEntrypoint(Threading::Thread* thread);
  void TaskLoop();

  Threading::ThreadPool thread_pool_;
  std::mutex state_mutex_;
  // Everything below should only be touched when mutex is locked
  std::condition_variable wake_signal_;
  std::queue<Task> task_queue_;
  int32_t idle_threads_{0};
  bool is_shutting_down_{false};
};
}  // namespace BoolkaEngine::TaskSystem

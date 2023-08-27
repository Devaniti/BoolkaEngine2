#include "precompiled_header.h"

#include "thread_pool.h"

#include "hardware_info.h"

namespace BoolkaEngine::Threading {

ThreadPool::ThreadPool() = default;

ThreadPool::~ThreadPool() { delete[] threads_; }

bool ThreadPool::Initialize(void (*entrypoint)(Thread*, void*),
                            void* parameters) {
  thread_count_ = HardwareInfo::HardwareInfo::GetProcessAffinityCoreCount();
  uint64_t affinity_mask = HardwareInfo::HardwareInfo::GetProcessAffinityMask();

  threads_ = new Thread[thread_count_];
  auto* i = threads_;

  while (affinity_mask) {
    uint64_t mask = affinity_mask & -affinity_mask;
    i++->Initialize(mask, entrypoint, parameters);
    affinity_mask = affinity_mask & ~mask;
  }

  return true;
}

void ThreadPool::Join() {
  for (Thread* i = threads_; i < threads_ + thread_count_; ++i) {
    i->Join();
  }
}

uint32_t ThreadPool::GetThreadCount() const { return thread_count_; }

}  // namespace BoolkaEngine::Threading

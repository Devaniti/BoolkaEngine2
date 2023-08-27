#pragma once

#include "thread.h"

namespace BoolkaEngine::Threading {

class ThreadPool {
 public:
  ThreadPool();
  ~ThreadPool();

  ThreadPool(const ThreadPool&) = delete;
  ThreadPool(ThreadPool&&) = delete;
  ThreadPool& operator=(const ThreadPool&) = delete;
  ThreadPool& operator=(ThreadPool&&) = delete;

  bool Initialize(void (*entrypoint)(Thread*, void*), void* parameters);
  void Join();

  [[nodiscard]] uint32_t GetThreadCount() const;

 private:
  Thread* threads_{nullptr};
  uint32_t thread_count_{0};
};

}  // namespace BoolkaEngine::Threading

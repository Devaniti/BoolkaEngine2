#pragma once

#include "thread.h"

namespace Threading {

class ThreadPool {
 public:
  ThreadPool();
  ~ThreadPool();

  bool Initialize(void (*entrypoint)(Thread*, void*), void* parameters);

 private:
  Thread* threads;
};

}  // namespace Threading

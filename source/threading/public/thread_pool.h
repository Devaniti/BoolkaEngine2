#pragma once

#include "thread.h"

class ThreadPool {
 public:
  ThreadPool();
  ~ThreadPool();

  bool Initialize(void (*entrypoint)(void*), void* parameters);

 private:
  Thread* threads;
};

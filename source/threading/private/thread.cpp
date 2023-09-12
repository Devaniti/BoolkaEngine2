#include "precompiled_header.h"

#include "thread.h"

namespace BoolkaEngine::Threading {

Thread::~Thread() {
#if defined(_WIN32) || defined(WIN32)
  if (thread_) {
    Join();
    ::CloseHandle(thread_);
  }
#elif __unix__
  if (thread_) {
    Join();
  }
#else
#error Unknown platform
#endif
}

bool Thread::Initialize(uint64_t affinity, void (*entrypoint)(Thread*, void*),
                        void* parameters) {
  BLK_ASSERT(entrypoint);

  affinity_ = affinity;
  entrypoint_ = entrypoint;
  user_parameters_ = parameters;

#if defined(_WIN32) || defined(WIN32)
  thread_ = ::CreateThread(nullptr, 0, &EntryPointWrapperStatic, this, 0,
                           &thread_id_);
  return thread_ != nullptr;
#elif __unix__
  if (pthread_create(&thread_, nullptr, &EntryPointWrapperStatic, this) == 0) {
    return true;
  } else {
    return false;
  }
#else
#error Unknown platform
#endif
}

void Thread::Join() {
#if defined(_WIN32) || defined(WIN32)
  ::WaitForSingleObject(thread_, INFINITE);
#elif __unix__
  pthread_join(thread_, nullptr);
#else
#error Unknown platform
#endif
}

uint64_t Thread::GetAffinity() const { return affinity_; }

uint64_t Thread::GetThreadID() const {
#if defined(_WIN32) || defined(WIN32)
  return static_cast<uint64_t>(thread_id_);
#elif __unix__
  return static_cast<uint64_t>(thread_);
#else
#error Unknown platform
#endif
}

#if defined(_WIN32) || defined(WIN32)
DWORD Thread::EntryPointWrapperStatic(void* parameters) {
  auto* thread = static_cast<Thread*>(parameters);
  thread->EntryPointWrapper();
  return 0;
}
#elif __unix__
void* Thread::EntryPointWrapperStatic(void* parameters) {
  auto* thread = static_cast<Thread*>(parameters);
  thread->EntryPointWrapper();
  return nullptr;
}
#else
#error Unknown platform
#endif

void Thread::EntryPointWrapper() {
#if defined(_WIN32) || defined(WIN32)
  HANDLE current_thread = GetCurrentThread();
  ::SetThreadAffinityMask(current_thread, GetAffinity());
  ::SwitchToThread();
#elif __unix__
  cpu_set_t cpuset;
  CPU_ZERO(&cpuset);
  CPU_SET(affinity_, &cpuset);
  pthread_setaffinity_np(thread_, sizeof(cpu_set_t), &cpuset);
  sched_yield();
#else
#error Unknown platform
#endif

  entrypoint_(this, user_parameters_);
}

}  // namespace BoolkaEngine::Threading

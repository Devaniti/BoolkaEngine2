#include "precompiled_header.h"

#include "thread.h"

namespace BoolkaEngine::Threading {

Thread::~Thread() {
  if (thread_) {
    Join();
    ::CloseHandle(thread_);
  }
}

bool Thread::Initialize(uint64_t affinity, void (*entrypoint)(Thread*, void*),
                        void* parameters) {
  BLK_ASSERT(entrypoint);

  affinity_ = affinity;
  entrypoint_ = entrypoint;
  user_parameters_ = parameters;

  thread_ = ::CreateThread(nullptr, 0, &EntryPointWrapperStatic, this, 0,
                           &thread_id_);

  return thread_ != nullptr;
}

void Thread::Join() {
  BLK_ASSERT(thread_);
  ::WaitForSingleObject(thread_, INFINITE);
}

uint64_t Thread::GetAffinity() const { return affinity_; }

DWORD Thread::GetThreadID() const { return thread_id_; }

DWORD Thread::EntryPointWrapperStatic(void* parameters) {
  auto* thread = static_cast<Thread*>(parameters);
  thread->EntryPointWrapper();
  return 0;
}

void Thread::EntryPointWrapper() {
  HANDLE current_thread = GetCurrentThread();
  ::SetThreadAffinityMask(current_thread, GetAffinity());
  ::SwitchToThread();

  entrypoint_(this, user_parameters_);
}

}  // namespace BoolkaEngine::Threading

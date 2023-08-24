#include "precompiled_header.h"

#include "thread.h"

namespace Threading {

Thread::Thread()
    : thread(NULL),
      affinity(0),
      entrypoint(nullptr),
      user_parameters(nullptr),
      thread_id(0) {}

Thread::~Thread() {
  if (thread) {
    ::WaitForSingleObject(thread, INFINITE);
    ::CloseHandle(thread);
  }
}

bool Thread::Initialize(uint64_t affinity, void (*entrypoint)(Thread*, void*),
                        void* parameters) {
  affinity = affinity;
  entrypoint = entrypoint;
  user_parameters = parameters;

  thread =
      ::CreateThread(NULL, 0, &EntryPointWrapperStatic, this, 0, &thread_id);

  return thread != NULL;
}

uint64_t Thread::GetAffinity() const { return affinity; }

DWORD Thread::GetThreadID() const { return thread_id; }

DWORD Thread::EntryPointWrapperStatic(void* parameters) {
  Thread* thread = static_cast<Thread*>(parameters);
  thread->EntryPointWrapper();
  return 0;
}

void Thread::EntryPointWrapper() {
  HANDLE current_thread = GetCurrentThread();
  ::SetThreadAffinityMask(current_thread, GetAffinity());
  ::SwitchToThread();

  entrypoint(this, user_parameters);
}

}  // namespace Threading

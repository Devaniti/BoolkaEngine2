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
    WaitForSingleObject(thread, INFINITE);
  }
}

bool Thread::Initialize(uint64_t affinity, void (*entrypoint)(void*),
                        void* parameters) {
  affinity = affinity;
  entrypoint = entrypoint;
  user_parameters = parameters;

  thread =
      ::CreateThread(NULL, 0, &EntryPointWrapperStatic, this, 0, &thread_id);

  return thread != NULL;
}

DWORD Thread::EntryPointWrapperStatic(void* parameters) {
  Thread* thread = static_cast<Thread*>(parameters);
  thread->EntryPointWrapper();
  return 0;
}

void Thread::EntryPointWrapper() {
  HANDLE current_thread = GetCurrentThread();
  SetThreadAffinityMask(current_thread, affinity);
  SwitchToThread();

  entrypoint(user_parameters);
}

}  // namespace Threading

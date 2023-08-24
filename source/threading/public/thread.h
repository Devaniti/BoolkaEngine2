#pragma once

namespace Threading {

class Thread {
 public:
  Thread();
  ~Thread();

  Thread(const Thread&) = delete;
  Thread(Thread&&) = delete;
  Thread& operator=(const Thread&) = delete;
  Thread& operator=(Thread&&) = delete;

  bool Initialize(uint64_t affinity, void (*entrypoint)(Thread*, void*),
                  void* parameters);

  uint64_t GetAffinity() const;
  DWORD GetThreadID() const;

 private:
  static DWORD WINAPI EntryPointWrapperStatic(void* parameters);
  void EntryPointWrapper();

  HANDLE thread;
  uint64_t affinity;
  void (*entrypoint)(Thread*, void*);
  void* user_parameters;
  DWORD thread_id;
};

}  // namespace Threading

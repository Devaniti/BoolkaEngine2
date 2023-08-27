#pragma once

namespace BoolkaEngine::Threading {

class Thread {
 public:
  Thread() = default;
  ~Thread();

  Thread(const Thread&) = delete;
  Thread(Thread&&) = delete;
  Thread& operator=(const Thread&) = delete;
  Thread& operator=(Thread&&) = delete;

  bool Initialize(uint64_t affinity, void (*entrypoint)(Thread*, void*),
                  void* parameters);
  void Join();

  [[nodiscard]] uint64_t GetAffinity() const;
  [[nodiscard]] DWORD GetThreadID() const;

 private:
  static DWORD WINAPI EntryPointWrapperStatic(void* parameters);
  void EntryPointWrapper();

  HANDLE thread_{nullptr};
  uint64_t affinity_{0};
  void (*entrypoint_)(Thread*, void*){nullptr};
  void* user_parameters_{nullptr};
  DWORD thread_id_{0};
};

}  // namespace BoolkaEngine::Threading

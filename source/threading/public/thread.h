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
  [[nodiscard]] uint64_t GetThreadID() const;

 private:
  void EntryPointWrapper();

  uint64_t affinity_{0};
  void (*entrypoint_)(Thread*, void*){nullptr};
  void* user_parameters_{nullptr};

#if defined(_WIN32) || defined(WIN32)
  static DWORD WINAPI EntryPointWrapperStatic(void* parameters);
  HANDLE thread_{nullptr};
  DWORD thread_id_{0};
#elif __unix__
  static void* EntryPointWrapperStatic(void* parameters);
  pthread_t thread_;
#else
#error Unknown platform
#endif
};

}  // namespace BoolkaEngine::Threading

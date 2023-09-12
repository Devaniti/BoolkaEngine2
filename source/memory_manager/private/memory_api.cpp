#include "precompiled_header.h"

#include "memory_api.h"

namespace BoolkaEngine::MemoryManager {

#if defined(_WIN32) || defined(WIN32)

void* MemoryAPI::Allocate(size_t size) noexcept {
  return VirtualAlloc(nullptr, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
}

void* MemoryAPI::Reserve(size_t size) noexcept {
  return VirtualAlloc(nullptr, size, MEM_RESERVE, PAGE_NOACCESS);
}

void MemoryAPI::Commit(void* adress, size_t size) noexcept {
  VirtualAlloc(adress, size, MEM_COMMIT, PAGE_READWRITE);
}

// Windows doesn't need allocation size when releasing
void MemoryAPI::Release(void* adress, size_t /*size*/) noexcept {
  VirtualFree(adress, 0, MEM_RELEASE);
}

void MemoryAPI::Decommit(void* adress, size_t size) noexcept {
#pragma warning(suppress : 6250)
  VirtualFree(adress, size, MEM_DECOMMIT);
}

#elif defined(__unix__)

void* MemoryAPI::Allocate(size_t size) noexcept {
  return mmap(nullptr, size, PROT_READ | PROT_WRITE,
              MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
}

void* MemoryAPI::Reserve(size_t size) noexcept {
  return mmap(nullptr, size, PROT_NONE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
}

void MemoryAPI::Commit(void* address, size_t size) noexcept {
  mprotect(address, size, PROT_READ | PROT_WRITE);
}

void MemoryAPI::Release(void* address, size_t size) noexcept {
  munmap(address, size);
}

void MemoryAPI::Decommit(void* address, size_t size) noexcept {
  // De-committing is essentially making the memory region unaccessible.
  mprotect(address, size, PROT_NONE);
}

#else
#error Unknown platform
#endif

}  // namespace BoolkaEngine::MemoryManager
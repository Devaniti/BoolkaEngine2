#pragma once

#ifdef BLK_DEBUG
#define BLK_LINEAR_ALLOCATOR_DEBUG
#endif

namespace BoolkaEngine::Allocator {
class BaseAllocator {
 public:
  virtual void* Allocate(size_t size) noexcept = 0;

  char* DuplicateString(const char* src);

  template <typename T, typename... Args>
  T* Emplace(Args&&... args);
};

}  // namespace BoolkaEngine::Allocator

#include "base_allocator.hpp"

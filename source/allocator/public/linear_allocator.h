#pragma once

#ifdef BLK_DEBUG
#define BLK_LINEAR_ALLOCATOR_DEBUG
#endif

namespace Allocator {
class LinearAllocator {
 public:
  explicit LinearAllocator(size_t max_size) noexcept;
  ~LinearAllocator() noexcept;

  LinearAllocator(const LinearAllocator& other) = delete;
  LinearAllocator& operator=(const LinearAllocator& other) = delete;
  LinearAllocator& operator=(LinearAllocator&& other) = delete;

  LinearAllocator(LinearAllocator&& other) noexcept;

  void* Allocate(size_t size) noexcept;
  void Reset() noexcept;

  template <typename T, typename... Args>
  T* Emplace(Args... args);

 private:
  void* start_;
  void* current_end_;
#ifdef BLK_LINEAR_ALLOCATOR_DEBUG
  // We only need end for detecting overflow
  void* end_;
#endif
};

}  // namespace Allocator

#include "linear_allocator.hpp"
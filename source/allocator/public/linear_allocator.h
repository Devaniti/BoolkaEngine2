#pragma once
#include "base_allocator.h"

#ifdef BLK_DEBUG
#define BLK_LINEAR_ALLOCATOR_DEBUG
#endif

namespace BoolkaEngine::Allocator {
class LinearAllocator : public BaseAllocator {
 public:
  explicit LinearAllocator(size_t max_size) noexcept;
  ~LinearAllocator() noexcept;

  LinearAllocator(const LinearAllocator& other) = delete;
  LinearAllocator& operator=(const LinearAllocator& other) = delete;

  LinearAllocator(LinearAllocator&& other) noexcept;
  LinearAllocator& operator=(LinearAllocator&& other) noexcept;

  void* Allocate(size_t size) noexcept override;
  void Reset() noexcept;

 private:
  void* start_;
  void* current_end_;
#ifdef BLK_LINEAR_ALLOCATOR_DEBUG
  // We only need end for detecting overflow
  void* end_;
#endif
};

}  // namespace BoolkaEngine::Allocator
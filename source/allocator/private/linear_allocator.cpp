#include "precompiled_header.h"

#include "linear_allocator.h"

#include "memory_allocator.h"

namespace BoolkaEngine::Allocator {

LinearAllocator::LinearAllocator(size_t max_size) noexcept
    : start_(MemoryManager::MemoryAllocator::Allocate(max_size)),
      current_end_(start_)
#ifdef BLK_LINEAR_ALLOCATOR_DEBUG
      ,
      end_(static_cast<char*>(start_) + max_size)
#endif
{
}

LinearAllocator::LinearAllocator(LinearAllocator&& other) noexcept
    : start_(other.start_),
      current_end_(other.current_end_)
#ifdef BLK_LINEAR_ALLOCATOR_DEBUG
      ,
      end_(other.end_)
#endif
{
  // Make sure other wasn't already move to something else
  BLK_ASSERT(other.start_ != nullptr);
  other.start_ = nullptr;
}

void* LinearAllocator::Allocate(size_t size) noexcept {
  // Make sure we aren't trying to allocate after moving this object to
  // something else
  BLK_ASSERT(start_ != nullptr);
  void* result = current_end_;
  current_end_ = static_cast<char*>(current_end_) + size;

#ifdef BLK_LINEAR_ALLOCATOR_DEBUG
  // Overflow
  BLK_ASSERT(current_end_ <= end_);
#endif

  return result;
}

void LinearAllocator::Reset() noexcept { current_end_ = start_; }

LinearAllocator::~LinearAllocator() noexcept {
  // If this object was moved to something else start is nullptr
  if (start_ != nullptr) {
    MemoryManager::MemoryAllocator::Release(start_);
  }
}

}  // namespace BoolkaEngine::Allocator

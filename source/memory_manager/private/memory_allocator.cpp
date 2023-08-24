#include "precompiled_header.h"

#include "memory_allocator.h"

namespace MemoryManager {

void* MemoryAllocator::Allocate(size_t size) noexcept { return malloc(size); }

void MemoryAllocator::Release(void* adress) noexcept { free(adress); }

}  // namespace MemoryManager

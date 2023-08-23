#include "precompiled_header.h"

#include "linear_allocator.h"

#include "memory_allocator.h"

namespace Allocator
{

	LinearAllocator::LinearAllocator(size_t max_size) noexcept
		: start(MemoryManager::MemoryAllocator::Allocate(max_size))
		, current_end(start)
#ifdef BLK_LINEAR_ALLOCATOR_DEBUG
		, end((char*)start + max_size)
#endif
	{
	}

	LinearAllocator::LinearAllocator(LinearAllocator&& other) noexcept
		: start(other.start)
		, current_end(other.current_end)
#ifdef BLK_LINEAR_ALLOCATOR_DEBUG
		, end(other.end)
#endif
	{
		// Make sure other wasn't already move to something else
		BLK_ASSERT(other.start != nullptr);
		other.start = nullptr;
	}

	void* LinearAllocator::Allocate(size_t size) noexcept
	{
		// Make sure we aren't trying to allocate after moving this object to something else
		BLK_ASSERT(start != nullptr);
		void* result = current_end;
		current_end = (char*)current_end + size;

#ifdef BLK_LINEAR_ALLOCATOR_DEBUG
		// Overflow
		BLK_ASSERT(current_end <= end);
#endif

		return result;
	}

	void LinearAllocator::Reset() noexcept
	{
		current_end = start;
	}

	LinearAllocator::~LinearAllocator() noexcept
	{
		// If this object was moved to something else start is nullptr
		if (start != nullptr)
		{
			MemoryManager::MemoryAllocator::Release(start);
		}
	}

}

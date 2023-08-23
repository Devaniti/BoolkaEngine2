#pragma once

namespace MemoryManager
{
	class MemoryAllocator
	{
	public:
		static void* Allocate(size_t size) noexcept;
		static void Release(void* adress) noexcept;
	};
}

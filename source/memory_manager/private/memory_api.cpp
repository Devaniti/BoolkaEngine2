#include "precompiled_header.h"

#include "memory_api.h"

namespace MemoryManager
{

	void* MemoryAPI::Allocate(size_t size) noexcept
	{
		return VirtualAlloc(nullptr, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	}

	void* MemoryAPI::Reserve(size_t size) noexcept
	{
		return VirtualAlloc(nullptr, size, MEM_RESERVE, PAGE_NOACCESS);
	}

	void MemoryAPI::Commit(void* adress, size_t size) noexcept
	{
		VirtualAlloc(adress, size, MEM_COMMIT, PAGE_READWRITE);
	}

	void MemoryAPI::Release(void* adress) noexcept
	{
		VirtualFree(adress, 0, MEM_RELEASE);
	}

	void MemoryAPI::Decommit(void* adress, size_t size) noexcept
	{
#pragma warning(suppress : 6250)
		VirtualFree(adress, size, MEM_DECOMMIT);
	}

}
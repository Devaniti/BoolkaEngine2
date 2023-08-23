#include "precompiled_header.h"

#include "thread_pool.h"

#include "hardware_info.h"

ThreadPool::ThreadPool()
	: threads(nullptr)
{
}

ThreadPool::~ThreadPool()
{
	if (threads != nullptr)
	{
		delete[] threads;
	}
}

bool ThreadPool::Initialize(void (*entrypoint)(void*), void* parameters)
{
	uint32_t core_count = HardwareInfo::HardwareInfo::GetProcessAffinityCoreCount();
	uint64_t affinity_mask = HardwareInfo::HardwareInfo::GetProcessAffinityMask();

	threads = new Thread[core_count];
	auto i = threads;

	while (affinity_mask)
	{
		uint64_t mask = affinity_mask & -affinity_mask;
		i++->Initialize(mask, entrypoint, parameters);
		affinity_mask = affinity_mask & ~mask;
	}

	return true;
}

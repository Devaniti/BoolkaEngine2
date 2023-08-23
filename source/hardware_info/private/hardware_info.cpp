#include "precompiled_header.h"

#include "hardware_info.h"

namespace HardwareInfo
{

	uint32_t HardwareInfo::cpu_core_count = 0;
	uint32_t HardwareInfo::process_affinity_core_count = 0;
	uint64_t HardwareInfo::process_affinity_mask = 0;
	uint64_t HardwareInfo::memory_size = 0;
	uint32_t HardwareInfo::page_size = 0;
	uint32_t HardwareInfo::allocation_granularity = 0;

#ifdef BLK_HARDWARE_INFO_DEBUG
	bool HardwareInfo::is_initialized = false;
#endif

	void HardwareInfo::Initialize()
	{
		InitializeThreadingParameters();
		InitializeMemoryParameters();
#ifdef BLK_HARDWARE_INFO_DEBUG
		is_initialized = true;
#endif
	}

	uint32_t HardwareInfo::GetCpuCoreCount()
	{
#ifdef BLK_HARDWARE_INFO_DEBUG
		BLK_ASSERT(is_initialized);
#endif
		return cpu_core_count;
	}

	uint32_t HardwareInfo::GetProcessAffinityCoreCount()
	{
#ifdef BLK_HARDWARE_INFO_DEBUG
		BLK_ASSERT(is_initialized);
#endif
		return process_affinity_core_count;
	}

	uint64_t HardwareInfo::GetProcessAffinityMask()
	{
#ifdef BLK_HARDWARE_INFO_DEBUG
		BLK_ASSERT(is_initialized);
#endif
		return process_affinity_mask;
	}

	uint64_t HardwareInfo::GetMemorySize()
	{
#ifdef BLK_HARDWARE_INFO_DEBUG
		BLK_ASSERT(is_initialized);
#endif
		return memory_size;
	}

	uint32_t HardwareInfo::GetPageSize()
	{
#ifdef BLK_HARDWARE_INFO_DEBUG
		BLK_ASSERT(is_initialized);
#endif
		return page_size;
	}

	uint32_t HardwareInfo::GetAllocationGranularity()
	{
#ifdef BLK_HARDWARE_INFO_DEBUG
		BLK_ASSERT(is_initialized);
#endif
		return allocation_granularity;
	}

	void HardwareInfo::InitializeThreadingParameters()
	{
#ifdef BLK_HARDWARE_INFO_DEBUG
		BLK_ASSERT(!is_initialized);
#endif
		cpu_core_count = ::GetActiveProcessorCount(0);
		HANDLE current_process = ::GetCurrentProcess();
		DWORD_PTR affinity_mask = 0;
		DWORD_PTR system_affinity_mask = 0;
		::GetProcessAffinityMask(current_process, &affinity_mask, &system_affinity_mask);
		process_affinity_core_count = std::popcount(affinity_mask);
		process_affinity_mask = affinity_mask;
	}

	void HardwareInfo::InitializeMemoryParameters()
	{
#ifdef BLK_HARDWARE_INFO_DEBUG
		BLK_ASSERT(!is_initialized);
#endif
		SYSTEM_INFO system_info;
		GetSystemInfo(&system_info);
		page_size = system_info.dwPageSize;
		allocation_granularity = system_info.dwAllocationGranularity;

		MEMORYSTATUSEX memory_status;
		memory_status.dwLength = sizeof(memory_status);
		GlobalMemoryStatusEx(&memory_status);
		memory_size = memory_status.ullTotalPhys;
	}

}

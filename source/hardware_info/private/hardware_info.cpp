#include "precompiled_header.h"

#include "hardware_info.h"

namespace BoolkaEngine::HardwareInfo {

uint32_t HardwareInfo::cpu_core_count_ = 0;
uint32_t HardwareInfo::process_affinity_core_count_ = 0;
uint64_t HardwareInfo::process_affinity_mask_ = 0;
uint64_t HardwareInfo::memory_size_ = 0;
uint32_t HardwareInfo::page_size_ = 0;
uint32_t HardwareInfo::allocation_granularity_ = 0;

#ifdef BLK_HARDWARE_INFO_DEBUG
bool HardwareInfo::is_initialized_ = false;
#endif

void HardwareInfo::Initialize() {
  InitializeThreadingParameters();
  InitializeMemoryParameters();
#ifdef BLK_HARDWARE_INFO_DEBUG
  is_initialized_ = true;
#endif
}

uint32_t HardwareInfo::GetCpuCoreCount() {
#ifdef BLK_HARDWARE_INFO_DEBUG
  BLK_ASSERT(is_initialized_);
#endif
  return cpu_core_count_;
}

uint32_t HardwareInfo::GetProcessAffinityCoreCount() {
#ifdef BLK_HARDWARE_INFO_DEBUG
  BLK_ASSERT(is_initialized_);
#endif
  return process_affinity_core_count_;
}

uint64_t HardwareInfo::GetProcessAffinityMask() {
#ifdef BLK_HARDWARE_INFO_DEBUG
  BLK_ASSERT(is_initialized_);
#endif
  return process_affinity_mask_;
}

uint64_t HardwareInfo::GetMemorySize() {
#ifdef BLK_HARDWARE_INFO_DEBUG
  BLK_ASSERT(is_initialized_);
#endif
  return memory_size_;
}

uint32_t HardwareInfo::GetPageSize() {
#ifdef BLK_HARDWARE_INFO_DEBUG
  BLK_ASSERT(is_initialized_);
#endif
  return page_size_;
}

uint32_t HardwareInfo::GetAllocationGranularity() {
#ifdef BLK_HARDWARE_INFO_DEBUG
  BLK_ASSERT(is_initialized_);
#endif
  return allocation_granularity_;
}

#if defined(_WIN32) || defined(WIN32)

void HardwareInfo::InitializeThreadingParameters() {
#ifdef BLK_HARDWARE_INFO_DEBUG
  BLK_ASSERT(!is_initialized_);
#endif
  cpu_core_count_ = ::GetActiveProcessorCount(0);
  HANDLE current_process = ::GetCurrentProcess();
  DWORD_PTR affinity_mask = 0;
  DWORD_PTR system_affinity_mask = 0;
  ::GetProcessAffinityMask(current_process, &affinity_mask,
                           &system_affinity_mask);
  process_affinity_core_count_ = std::popcount(affinity_mask);
  process_affinity_mask_ = affinity_mask;
}

void HardwareInfo::InitializeMemoryParameters() {
#ifdef BLK_HARDWARE_INFO_DEBUG
  BLK_ASSERT(!is_initialized_);
#endif
  SYSTEM_INFO system_info;
  GetSystemInfo(&system_info);
  page_size_ = system_info.dwPageSize;
  allocation_granularity_ = system_info.dwAllocationGranularity;

  MEMORYSTATUSEX memory_status;
  memory_status.dwLength = sizeof(memory_status);
  GlobalMemoryStatusEx(&memory_status);
  memory_size_ = memory_status.ullTotalPhys;
}

#elif defined(__unix__)

void HardwareInfo::InitializeThreadingParameters() {
#ifdef BLK_HARDWARE_INFO_DEBUG
  BLK_ASSERT(!is_initialized_);
#endif
  cpu_core_count_ = sysconf(_SC_NPROCESSORS_CONF);
  cpu_set_t mask{};
  sched_getaffinity(0, sizeof(mask), &mask);
  process_affinity_mask_ = *(uint64_t*)(&mask);
  process_affinity_core_count_ = std::popcount(process_affinity_mask_);
}

void HardwareInfo::InitializeMemoryParameters() {
#ifdef BLK_HARDWARE_INFO_DEBUG
  BLK_ASSERT(!is_initialized_);
#endif
  struct sysinfo mem_info;
  sysinfo(&mem_info);

  memory_size_ = mem_info.totalram * mem_info.mem_unit;
  page_size_ = sysconf(_SC_PAGESIZE);
  allocation_granularity_ =
      sysconf(_SC_PAGESIZE);  // In Linux, allocation granularity is often the
                              // same as the page size
}

#else
#error Unknown platform
#endif

}  // namespace BoolkaEngine::HardwareInfo

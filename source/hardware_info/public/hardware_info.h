#pragma once

#include "precompiled_header.h"

#ifdef BLK_DEBUG
#define BLK_HARDWARE_INFO_DEBUG
#endif

namespace HardwareInfo {
class HardwareInfo {
 public:
  static void Initialize();

  // Threading parameters
  static uint32_t GetCpuCoreCount();
  static uint32_t GetProcessAffinityCoreCount();
  static uint64_t GetProcessAffinityMask();

  // Memory parameters
  static uint64_t GetMemorySize();
  static uint32_t GetPageSize();
  static uint32_t GetAllocationGranularity();

 private:
  static void InitializeThreadingParameters();
  static void InitializeMemoryParameters();

  // Threading parameters
  static uint32_t cpu_core_count_;
  static uint32_t process_affinity_core_count_;
  static uint64_t process_affinity_mask_;

  // Memory parameters
  static uint64_t memory_size_;
  static uint32_t page_size_;
  static uint32_t allocation_granularity_;

#ifdef BLK_HARDWARE_INFO_DEBUG
  static bool is_initialized_;
#endif
};
}  // namespace HardwareInfo

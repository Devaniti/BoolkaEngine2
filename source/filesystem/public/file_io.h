#pragma once

#include "memory_block.h"

namespace BoolkaEngine::Filesystem {

class FileIO {
 public:
  static MemoryManager::MemoryBlock ReadFile(const std::filesystem::path& path);
};

}  // namespace BoolkaEngine::Filesystem

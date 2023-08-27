#pragma once

#include "element.h"
#include "linear_allocator.h"
#include "memory_block.h"

namespace BoolkaEngine::RGParser {

class Parser {
 public:
  [[nodiscard]] static Element* Parse(const MemoryManager::MemoryBlock& data,
                                      Allocator::LinearAllocator& allocator);
};

}  // namespace BoolkaEngine::RGParser

#pragma once

#include "element.h"

#include "linear_allocator.h"
#include "memory_block.h"

namespace RGParser
{

    using namespace Allocator;

    class Parser
    {
    public:
        [[nodiscard]] static Element* Parse(const MemoryManager::MemoryBlock& data, LinearAllocator& allocator);
    };

}

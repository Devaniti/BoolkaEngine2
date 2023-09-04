#pragma once

#include "linear_allocator.h"
#include "resources/resource.h"
#include "variables/variable.h"

namespace BoolkaEngine::RenderGraphParser {
struct ParserContext {
  ParserContext();

  Allocator::LinearAllocator scratch_memory;
};
}  // namespace BoolkaEngine::RenderGraphParser

#pragma once

#include "precompiled_header.h"

#include "linear_allocator.h"
#include "render_graph.h"

namespace BoolkaEngine::RenderGraphParser {
class Parser {
 public:
  static RenderGraph* Parse(const char* source_folder,
                     Allocator::LinearAllocator& allocator);
};
}  // namespace BoolkaEngine::RenderGraphParser

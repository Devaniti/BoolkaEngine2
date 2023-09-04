#pragma once

#include "linear_allocator.h"
#include "resources/resource.h"
#include "variables/variable.h"

namespace BoolkaEngine::RenderGraphParser {
struct RenderGraph {
  RenderGraph() noexcept;
  explicit RenderGraph(Allocator::LinearAllocator&& allocator) noexcept;

  std::vector<std::pair<const char*, Variable>> variables;
  std::vector<std::pair<const char*, Resource>> resources;
  Allocator::LinearAllocator allocator;
};
}  // namespace BoolkaEngine::RenderGraphParser

#pragma once

#include "linear_allocator.h"
#include "resources/resource.h"
#include "variables/variable.h"

namespace BoolkaEngine::RenderGraphParser {
struct RenderGraph {
  RenderGraph();
  explicit RenderGraph(Allocator::LinearAllocator&& allocator);

  std::unordered_map<std::string_view, Variable*> variables;
  std::unordered_map<std::string_view, Resource*> resources;
  Allocator::LinearAllocator allocator;
};
}  // namespace BoolkaEngine::RenderGraphParser

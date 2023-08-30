#pragma once

#include "precompiled_header.h"

#include "resources/resource.h"

namespace BoolkaEngine::RenderGraphParser {
struct ObjectContainer {
  std::vector<std::pair<std::string, Resource>> resources;
};
}  // namespace BoolkaEngine::RenderGraphParser

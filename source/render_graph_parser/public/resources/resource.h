#pragma once

#include "precompiled_header.h"

#include "resource_view_continer.h"

namespace BoolkaEngine::RenderGraphParser {
enum class ResourceType { Buffer, Texture1D, Texture2D, Texture3D };

struct Resource {
  const char* name;
  ResourceType type;
  union {};
};
}  // namespace BoolkaEngine::RenderGraphParser

#pragma once

#include "buffer.h"
#include "texture1d.h"
#include "texture2d.h"
#include "texture3d.h"

namespace BoolkaEngine::RenderGraphParser {
enum class ResourceType { Buffer, Texture1D, Texture2D, Texture3D };

struct Resource {
  const char* name;
  ResourceType type;
  union {
    Buffer buffer;
    Texture1D texture1D;
    Texture2D texture2D;
    Texture3D texture3D;
  };
};
}  // namespace BoolkaEngine::RenderGraphParser

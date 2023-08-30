#pragma once

#include "precompiled_header.h"

namespace BoolkaEngine::RenderGraphParser {
struct Texture3D{
  const char* format;
  Variable* resolution;
  float4 optimized_clear_value;
};
}  // namespace BoolkaEngine::RenderGraphParser

#pragma once

#include "precompiled_header.h"

#include "variable.h"

namespace BoolkaEngine::RenderGraphParser {
struct Texture {
  const char* format;
  Variable* resolution;
  float4 optimized_clear_value;
};
}  // namespace BoolkaEngine::RenderGraphParser

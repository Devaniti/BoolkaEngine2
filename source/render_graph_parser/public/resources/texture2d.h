#pragma once

#include "precompiled_header.h"

namespace BoolkaEngine::RenderGraphParser {
struct Texture2D {
  const char* format;
  Variable* resolution;
  float4 optimized_clear_value;
  const Variable* slice_count;
};
}  // namespace BoolkaEngine::RenderGraphParser

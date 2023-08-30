#pragma once

#include "precompiled_header.h"

namespace BoolkaEngine::RenderGraphParser {
struct Texture1D {
  const char* format;
  Variable* resolution;
  float4 optimized_clear_value;
  const char* slice_count;
};
}  // namespace BoolkaEngine::RenderGraphParser

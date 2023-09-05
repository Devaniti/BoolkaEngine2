#pragma once

#include "resource_format.h"
#include "variables/variable.h"

namespace BoolkaEngine::RenderGraphParser {
struct Texture2D {
  ResourceFormat format;

  union {
    const Variable* resolution;
    const char* resolution_name;
  };

  union {
    const Variable* optimized_clear_value;
    const char* optimized_clear_value_name;
  };

  union {
    const Variable* slice_count;
    const char* slice_count_name;
  };
};
}  // namespace BoolkaEngine::RenderGraphParser

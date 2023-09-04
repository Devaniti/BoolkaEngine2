#pragma once

#include "resource_format.h"
#include "variables/variable.h"

namespace BoolkaEngine::RenderGraphParser {
struct Texture1D {
  ResourceFormat format;
  const Variable* resolution;
  const Variable* optimized_clear_value;
  const Variable* slice_count;
};
}  // namespace BoolkaEngine::RenderGraphParser

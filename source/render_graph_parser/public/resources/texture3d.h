#pragma once

#include "resource_format.h"
#include "variables/variable.h"

namespace BoolkaEngine::RenderGraphParser {
struct Texture3D {
  ResourceFormat format;
  const Variable* resolution;
  const Variable* optimized_clear_value;
};
}  // namespace BoolkaEngine::RenderGraphParser

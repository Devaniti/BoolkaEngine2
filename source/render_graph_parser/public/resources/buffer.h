#pragma once

#include "resource_format.h"
#include "variables/variable.h"

namespace BoolkaEngine::RenderGraphParser {
struct Buffer {
  ResourceFormat format;
  const Variable* size;
};
}  // namespace BoolkaEngine::RenderGraphParser

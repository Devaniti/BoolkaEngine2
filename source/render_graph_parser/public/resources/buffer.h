#pragma once

#include "resource_format.h"
#include "variables/variable.h"

namespace BoolkaEngine::RenderGraphParser {
struct Buffer {
  ResourceFormat format;
  union {
    const Variable* size;
    const char* size_name;
  };
};
}  // namespace BoolkaEngine::RenderGraphParser

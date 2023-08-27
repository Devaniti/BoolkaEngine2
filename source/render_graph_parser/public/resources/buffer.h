#pragma once

#include "precompiled_header.h"

#include "format.h"
#include "variable.h"

namespace BoolkaEngine::RenderGraphParser {
struct Buffer {
  Format format;
  Variable* size;
};
}  // namespace BoolkaEngine::RenderGraphParser

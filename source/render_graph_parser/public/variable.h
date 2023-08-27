#pragma once

#include "precompiled_header.h"

namespace BoolkaEngine::RenderGraphParser {

struct Variable {
  enum class UpdateFrequency { Stall, Frame };

  const char* name;
  const char* format;
  UpdateFrequency update_frequency;
};
}  // namespace BoolkaEngine::RenderGraphParser

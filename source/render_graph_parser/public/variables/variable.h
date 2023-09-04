#pragma once

#include "variable_format.h"

namespace BoolkaEngine::RenderGraphParser {

struct Variable {
  enum class UpdateFrequency { Stall, Frame };

  VariableFormat format;
  UpdateFrequency update_frequency;
};
}  // namespace BoolkaEngine::RenderGraphParser

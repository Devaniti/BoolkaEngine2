#pragma once

#include "variable_format.h"
#include "variable_update_frequency.h"

namespace BoolkaEngine::RenderGraphParser {

struct Variable {
  VariableFormat format;
  VariableUpdateFrequency update_frequency;
};
}  // namespace BoolkaEngine::RenderGraphParser

#include "precompiled_header.h"

#include "variables/variable_update_frequency.h"

#include <render_graph_parser.h>

namespace BoolkaEngine::RenderGraphParser {

VariableUpdateFrequency ToVariableUpdateFrequency(size_t token) {
  switch (token) {
    case render_graph_parser::CONST:
      return VariableUpdateFrequency::Const;
    case render_graph_parser::STALL:
      return VariableUpdateFrequency::Stall;
    case render_graph_parser::FRAME:
      return VariableUpdateFrequency::Frame;
    default:
      assert(0);
      return VariableUpdateFrequency::Const;
  }
}

}  // namespace BoolkaEngine::RenderGraphParser

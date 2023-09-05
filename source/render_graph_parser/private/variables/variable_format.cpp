#include "precompiled_header.h"

#include "variables/variable_format.h"

#include <render_graph_parser.h>

namespace BoolkaEngine::RenderGraphParser {

VariableFormat ToVariableFormat(size_t token) {
  switch (token) {
    case render_graph_parser::UINT:
      return VariableFormat::Uint;
    case render_graph_parser::UINT2:
      return VariableFormat::Uint2;
    case render_graph_parser::UINT3:
      return VariableFormat::Uint3;
    case render_graph_parser::UINT4:
      return VariableFormat::Uint4;
    case render_graph_parser::FLOAT:
      return VariableFormat::Float;
    case render_graph_parser::FLOAT2:
      return VariableFormat::Float2;
    case render_graph_parser::FLOAT3:
      return VariableFormat::Float3;
    case render_graph_parser::FLOAT4:
      return VariableFormat::Float4;
    default:
      assert(0);
      return VariableFormat::Uint;
  }
}

}  // namespace BoolkaEngine::RenderGraphParser

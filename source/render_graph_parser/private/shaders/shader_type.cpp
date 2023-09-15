#include "precompiled_header.h"

#include "shaders/shader_type.h"

#include <render_graph_parser.h>

namespace BoolkaEngine::RenderGraphParser {

ShaderType ToShaderType(size_t token) {
  switch (token) {
    case render_graph_parser::VS:
      return ShaderType::VS;
    case render_graph_parser::AS:
      return ShaderType::AS;
    case render_graph_parser::MS:
      return ShaderType::MS;
    case render_graph_parser::PS:
      return ShaderType::PS;
    case render_graph_parser::CS:
      return ShaderType::CS;
    default:
      assert(0);
      return ShaderType::VS;
  }
}

}  // namespace BoolkaEngine::RenderGraphParser

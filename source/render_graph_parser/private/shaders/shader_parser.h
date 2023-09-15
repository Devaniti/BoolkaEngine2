#pragma once

#include <render_graph_parser.h>

#include "parser_context.h"
#include "render_graph.h"
#include "resources/resource.h"

namespace BoolkaEngine::RenderGraphParser {
class ShaderParser {
 public:
  static void Parse(RenderGraph& graph, ParserContext& parser_context,
                    render_graph_parser::ShaderContext* context);

 private:
  static Shader ParseObjectBody(
      RenderGraph& graph, render_graph_parser::ShaderBodyContext* context);
};

}  // namespace BoolkaEngine::RenderGraphParser

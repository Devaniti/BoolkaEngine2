#pragma once

#include <render_graph_parser.h>

#include "parser_context.h"
#include "render_graph.h"
#include "resources/resource.h"

namespace BoolkaEngine::RenderGraphParser {
class VariableParser {
 public:
  static void Parse(RenderGraph& graph, ParserContext& parser_context,
                    render_graph_parser::VariableContext* context);

 private:
  static Variable ParseObjectBody(
      ParserContext& parser_context,
      render_graph_parser::VariableBodyContext* context);
};
}  // namespace BoolkaEngine::RenderGraphParser

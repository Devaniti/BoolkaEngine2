#pragma once

#include <render_graph_parser.h>

#include "parser_context.h"
#include "render_graph.h"
#include "resources/texture3d.h"

namespace BoolkaEngine::RenderGraphParser {
class Texture3DParser {
 public:
  static Texture3D Parse(ParserContext& parser_context,
                         render_graph_parser::ResourceBodyContext* context);
  static void Linkup(const RenderGraph& graph, Texture3D& texture);
};
}  // namespace BoolkaEngine::RenderGraphParser

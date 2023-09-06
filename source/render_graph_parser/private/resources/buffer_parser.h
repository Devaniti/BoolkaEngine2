#pragma once

#include <render_graph_parser.h>

#include "parser_context.h"
#include "render_graph.h"
#include "resources/buffer.h"

namespace BoolkaEngine::RenderGraphParser {
class BufferParser {
 public:
  static Buffer Parse(ParserContext& parser_context,
                      render_graph_parser::ResourceBodyContext* context);
  static void Linkup(const RenderGraph& graph, Buffer& buffer);
};
}  // namespace BoolkaEngine::RenderGraphParser

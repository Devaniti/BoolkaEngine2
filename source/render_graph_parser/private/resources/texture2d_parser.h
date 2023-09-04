#pragma once

#include <render_graph_parser.h>

#include "parser_context.h"
#include "resources/texture2d.h"

namespace BoolkaEngine::RenderGraphParser {
class Texture2DParser {
 public:
  static Texture2D Parse(ParserContext& parser_context,
                         render_graph_parser::ResourceBodyContext* context);
};
}  // namespace BoolkaEngine::RenderGraphParser

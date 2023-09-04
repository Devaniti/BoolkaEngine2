#pragma once

#include <render_graph_parser.h>

#include "parser_context.h"
#include "resources/texture1d.h"

namespace BoolkaEngine::RenderGraphParser {
class Texture1DParser {
 public:
  static Texture1D Parse(ParserContext& parser_context,
                         render_graph_parser::ResourceBodyContext* context);
};
}  // namespace BoolkaEngine::RenderGraphParser

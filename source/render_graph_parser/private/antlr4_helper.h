#pragma once

#include <render_graph_parser.h>

#include "parser_context.h"
#include "variables/variable.h"

namespace BoolkaEngine::RenderGraphParser {
class Antlr4Helper {
 public:
  static size_t GetToken(antlr4::ParserRuleContext* context);
  static Variable* AllocateFakeVariable(ParserContext& parser_context,
                                        const std::string& name);
};
}  // namespace BoolkaEngine::RenderGraphParser

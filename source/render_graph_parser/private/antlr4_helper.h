#pragma once

#include <render_graph_parser.h>

#include "parser_context.h"
#include "variables/variable.h"

namespace BoolkaEngine::RenderGraphParser {
class Antlr4Helper {
 public:
  static size_t GetToken(antlr4::ParserRuleContext* context);
  template <typename T>
  static const char* GetID(ParserContext& parser_context, T* src,
                           bool allow_null = true);
};

}  // namespace BoolkaEngine::RenderGraphParser

#include "antlr4_helper.hpp"

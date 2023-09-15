#pragma once

#include <render_graph_parser.h>

#include "parser_context.h"
#include "render_graph.h"
#include "variables/variable.h"

namespace BoolkaEngine::RenderGraphParser {
class Antlr4Helper {
 public:
  static size_t GetToken(antlr4::ParserRuleContext* context);
  template <typename T>
  static const char* GetTempID(ParserContext& parser_context, T* src,
                               bool allow_null = true);
  template <typename T>
  static const char* GetID(RenderGraph& graph, T* src, bool allow_null = true);
  template <typename T>
  static const char* GetFilePath(RenderGraph& graph, T* src,
                                 bool allow_null = true);
  static Variable* GetVariable(const RenderGraph& graph, const char* name,
                               bool allow_null = true);
};

}  // namespace BoolkaEngine::RenderGraphParser

#include "antlr4_helper.hpp"

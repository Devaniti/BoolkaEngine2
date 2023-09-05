#pragma once

#include "linear_allocator.h"
#include "render_graph.h"

namespace BoolkaEngine::RenderGraphParser {
struct ParserContext;

class Parser {
 public:
  static RenderGraph* Parse(const char* source_folder);

 private:
  static void ParseFiles(const char* source_folder, RenderGraph* graph,
                         ParserContext& parser_context);
  static void LinkupStep(RenderGraph* graph);
};
}  // namespace BoolkaEngine::RenderGraphParser

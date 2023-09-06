#pragma once

#include <render_graph_parser.h>

#include "parser_context.h"
#include "render_graph.h"
#include "resources/resource.h"

namespace BoolkaEngine::RenderGraphParser {
class ResourceParser {
 public:
  static void Parse(RenderGraph& graph, ParserContext& parser_context,
                    render_graph_parser::ResourceContext* context);
  static void Linkup(const RenderGraph& graph, Resource& resource);

 private:
  static ResourceType ParseType(
      render_graph_parser::ResourceTypeValueContext* type);
  static Resource ParseObjectBody(
      ParserContext& parser_context,
      render_graph_parser::ResourceBodyContext* body);
};
}  // namespace BoolkaEngine::RenderGraphParser

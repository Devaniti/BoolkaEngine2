#include "precompiled_header.h"

#include "resource_parser.h"

#include "antlr4_helper.h"
#include "buffer_parser.h"
#include "texture1d_parser.h"
#include "texture2d_parser.h"
#include "texture3d_parser.h"

namespace BoolkaEngine::RenderGraphParser {
void ResourceParser::Parse(RenderGraph& graph, ParserContext& parser_context,
                           render_graph_parser::ResourceContext* context) {
  std::string name = context->ID()->getText();
  Resource result = ParseObjectBody(parser_context, context->resourceBody());

  graph.resources.emplace_back(graph.allocator.DuplicateString(name.c_str()),
                               result);
}

ResourceType ResourceParser::ParseType(
    render_graph_parser::ResourceTypeValueContext* type) {
  switch (Antlr4Helper::GetToken(type)) {
    case render_graph_parser::BUFFER:
      return ResourceType::Buffer;
    case render_graph_parser::TEXTURE1D:
      return ResourceType::Texture1D;
    case render_graph_parser::TEXTURE2D:
      return ResourceType::Texture2D;
    case render_graph_parser::TEXTURE3D:
      return ResourceType::Texture3D;
    default:
      assert(0);
  }

  return static_cast<ResourceType>(0);
}

Resource ResourceParser::ParseObjectBody(
    ParserContext& parser_context,
    render_graph_parser::ResourceBodyContext* body) {
  Resource result;
  result.type = ParseType(body->typeDeclaration()->resourceTypeValue());

  switch (result.type) {
    case ResourceType::Buffer:
      result.buffer = BufferParser::Parse(parser_context, body);
      break;
    case ResourceType::Texture1D:
      result.texture1D = Texture1DParser::Parse(parser_context, body);
      break;
    case ResourceType::Texture2D:
      result.texture2D = Texture2DParser::Parse(parser_context, body);
      break;
    case ResourceType::Texture3D:
      result.texture3D = Texture3DParser::Parse(parser_context, body);
      break;
    default:
      assert(0);
      break;
  }

  return result;
}

}  // namespace BoolkaEngine::RenderGraphParser

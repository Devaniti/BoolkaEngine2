#include "precompiled_header.h"

#include "resource_parser.h"

namespace BoolkaEngine::RenderGraphParser {
void ResourceParser::Parse(ObjectContainer& container,
                           render_graph_parser::ResourceContext* resource) {
  std::string name = resource->ID()->getText();
  Resource result = ParseObjectBody(resource->resourceBody());

  container.resources.emplace_back(name, result);
}

ResourceType ResourceParser::ParseType(
    render_graph_parser::ResourceTypeValueContext* type) {
  assert(dynamic_cast<antlr4::tree::TerminalNode*>(type->children[0]));
  auto node = static_cast<antlr4::tree::TerminalNode*>(type->children[0]);
  antlr4::Token* token = node->getSymbol();

  auto test = token->getType();

  switch (token->getType()) {
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

  return ResourceType(0);
}

BoolkaEngine::RenderGraphParser::Buffer ResourceParser::ParseBuffer(
    render_graph_parser::ResourceBodyContext* body) {
  throw std::logic_error("Unimplemented");
}

BoolkaEngine::RenderGraphParser::Texture1D ResourceParser::ParseTexture1D(
    render_graph_parser::ResourceBodyContext* body) {
  throw std::logic_error("Unimplemented");
}

BoolkaEngine::RenderGraphParser::Texture2D ResourceParser::ParseTexture2D(
    render_graph_parser::ResourceBodyContext* body) {
  return Texture2D{.format = 0,
                   .resolution = 0,
                   .optimized_clear_value = 0,
                   .slice_count = 0};
  throw std::logic_error("Unimplemented");
}

BoolkaEngine::RenderGraphParser::Texture3D ResourceParser::ParseTexture3D(
    render_graph_parser::ResourceBodyContext* body) {
  throw std::logic_error("Unimplemented");
}

BoolkaEngine::RenderGraphParser::Resource ResourceParser::ParseObjectBody(
    render_graph_parser::ResourceBodyContext* body) {
  Resource result;
  result.type = ParseType(body->typeDeclaration()->resourceTypeValue());

  switch (result.type) {
    case ResourceType::Buffer:
      result.buffer = ParseBuffer(body);
      break;
    case ResourceType::Texture1D:
      result.texture1D = ParseTexture1D(body);
      break;
    case ResourceType::Texture2D:
      result.texture2D = ParseTexture2D(body);
      break;
    case ResourceType::Texture3D:
      result.texture3D = ParseTexture3D(body);
      break;
    default:
      assert(0);
      break;
  }

  return result;
}

}  // namespace BoolkaEngine::RenderGraphParser

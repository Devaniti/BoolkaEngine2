#include "precompiled_header.h"

#include "texture3d_parser.h"

#include "antlr4_helper.h"

namespace BoolkaEngine::RenderGraphParser {

Texture3D Texture3DParser::Parse(
    ParserContext& parser_context,
    render_graph_parser::ResourceBodyContext* context) {
  return Texture3D{
      .format = ToResourceFormat(Antlr4Helper::GetToken(
          context->resourceFormatDeclaration()->resourceFormatValue())),
      .resolution_name = Antlr4Helper::GetID(
          parser_context, context->resolutionDeclaration(), false),
      .optimized_clear_value_name = Antlr4Helper::GetID(
          parser_context, context->optimizedClearValueDeclaration())};
}

}  // namespace BoolkaEngine::RenderGraphParser

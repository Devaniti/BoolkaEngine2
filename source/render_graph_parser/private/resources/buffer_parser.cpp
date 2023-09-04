#include "precompiled_header.h"

#include "buffer_parser.h"

#include "antlr4_helper.h"

namespace BoolkaEngine::RenderGraphParser {

Buffer BufferParser::Parse(ParserContext& parser_context,
                           render_graph_parser::ResourceBodyContext* context) {
  return Buffer{
      .format = (context->resourceFormatDeclaration()
                     ? ToResourceFormat(Antlr4Helper::GetToken(
                           context->resourceFormatDeclaration()
                               ->resourceFormatValue()))
                     : ResourceFormat::None),
      .size = Antlr4Helper::AllocateFakeVariable(
          parser_context, context->sizeDeclaration()->ID()->getText())};
}

}  // namespace BoolkaEngine::RenderGraphParser

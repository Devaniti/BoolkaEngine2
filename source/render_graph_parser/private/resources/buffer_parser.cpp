#include "precompiled_header.h"

#include "buffer_parser.h"

#include "antlr4_helper.h"

namespace BoolkaEngine::RenderGraphParser {

Buffer BufferParser::Parse(ParserContext& parser_context,
                           render_graph_parser::ResourceBodyContext* context) {
  return Buffer{.format = (context->resourceFormatDeclaration()
                               ? ToResourceFormat(Antlr4Helper::GetToken(
                                     context->resourceFormatDeclaration()
                                         ->resourceFormatValue()))
                               : ResourceFormat::None),
                .size_name = Antlr4Helper::GetTempID(
                    parser_context, context->sizeDeclaration(), false)};
}

void BufferParser::Linkup(const RenderGraph& graph, Buffer& buffer) {
  buffer.size = Antlr4Helper::GetVariable(graph, buffer.size_name, false);
}

}  // namespace BoolkaEngine::RenderGraphParser

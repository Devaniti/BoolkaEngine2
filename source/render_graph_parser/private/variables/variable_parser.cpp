#include "precompiled_header.h"

#include "variable_parser.h"

#include "antlr4_helper.h"

namespace BoolkaEngine::RenderGraphParser {
void VariableParser::Parse(RenderGraph& graph, ParserContext& parser_context,
                           render_graph_parser::VariableContext* context) {
  auto* result = graph.allocator.Emplace<Variable>(
      ParseObjectBody(parser_context, context->variableBody()));
  result->name = graph.allocator.DuplicateString(context->ID()->getText());

  graph.variables.emplace(result->name, result);
}

BoolkaEngine::RenderGraphParser::Variable VariableParser::ParseObjectBody(
    ParserContext& /*parser_context*/,
    render_graph_parser::VariableBodyContext* context) {
  return Variable{
      .format = ToVariableFormat(Antlr4Helper::GetToken(
          context->variableFormatDeclaration()->variableFormatValue())),
      .update_frequency = ToVariableUpdateFrequency(Antlr4Helper::GetToken(
          context->updateFrequencyDeclaration()->updateFrequencyValue()))};
}

}  // namespace BoolkaEngine::RenderGraphParser

#include "precompiled_header.h"

#include "shader_parser.h"

#include "antlr4_helper.h"

namespace BoolkaEngine::RenderGraphParser {

void ShaderParser::Parse(RenderGraph& graph, ParserContext&  /*parser_context*/,
                         render_graph_parser::ShaderContext* context) {
  auto* result = graph.allocator.Emplace<Shader>(
      ParseObjectBody(graph, context->shaderBody()));
  result->type = ToShaderType(Antlr4Helper::GetToken(context->shaderType()));
  result->name = graph.allocator.DuplicateString(context->ID()->getText());

  graph.shaders.emplace(result->name, result);
}

BoolkaEngine::RenderGraphParser::Shader ShaderParser::ParseObjectBody(
    RenderGraph& graph, render_graph_parser::ShaderBodyContext* context) {
  return Shader{.filename = Antlr4Helper::GetFilePath(
                    graph, context->filenameDeclaration(), false),
                .entrypoint = Antlr4Helper::GetID(
                    graph, context->entrypointDeclaration(), false)};
}
}  // namespace BoolkaEngine::RenderGraphParser

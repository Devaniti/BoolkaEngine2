#pragma once

namespace BoolkaEngine::RenderGraphParser {

template <typename T>
const char* BoolkaEngine::RenderGraphParser::Antlr4Helper::GetTempID(
    ParserContext& parser_context, T* src, bool allow_null /*= true*/) {
  if (!allow_null) {
    assert(src != nullptr);
  }

  if (src == nullptr) {
    return nullptr;
  }

  return parser_context.scratch_memory.DuplicateString(src->ID()->getText());
}

template <typename T>
const char* BoolkaEngine::RenderGraphParser::Antlr4Helper::GetID(
    RenderGraph& graph, T* src, bool allow_null /*= true*/) {
  if (!allow_null) {
    assert(src != nullptr);
  }

  if (src == nullptr) {
    return nullptr;
  }

  return graph.allocator.DuplicateString(src->ID()->getText());
}

template <typename T>
const char* BoolkaEngine::RenderGraphParser::Antlr4Helper::GetFilePath(
    RenderGraph& graph, T* src, bool allow_null /*= true*/) {
  if (!allow_null) {
    assert(src != nullptr);
  }

  if (src == nullptr) {
    return nullptr;
  }

  return graph.allocator.DuplicateString(src->FILEPATH_VALUE()->getText());
}

}  // namespace BoolkaEngine::RenderGraphParser

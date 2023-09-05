#pragma once

namespace BoolkaEngine::RenderGraphParser {

template <typename T>
const char* BoolkaEngine::RenderGraphParser::Antlr4Helper::GetID(
    ParserContext& parser_context, T* src, bool allow_null /*= true*/) {
  if (!allow_null) {
    assert(src != nullptr);
  }

  if (src == nullptr) {
    return nullptr;
  }

  return parser_context.scratch_memory.DuplicateString(src->ID()->getText());
}

}  // namespace BoolkaEngine::RenderGraphParser

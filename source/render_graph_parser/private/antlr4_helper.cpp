#include "precompiled_header.h"

#include "antlr4_helper.h"

namespace BoolkaEngine::RenderGraphParser {

size_t Antlr4Helper::GetToken(antlr4::ParserRuleContext* context) {
  assert(context);
  assert(dynamic_cast<antlr4::tree::TerminalNode*>(context->children[0]));
  auto* node = static_cast<antlr4::tree::TerminalNode*>(context->children[0]);
  return node->getSymbol()->getType();
}

Variable* Antlr4Helper::AllocateFakeVariable(ParserContext& parser_context,
                                             const std::string& name) {
  return reinterpret_cast<Variable*>(
      parser_context.scratch_memory.DuplicateString(name.c_str()));
}

}  // namespace BoolkaEngine::RenderGraphParser

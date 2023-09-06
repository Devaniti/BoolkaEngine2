#include "precompiled_header.h"

#include "antlr4_helper.h"

namespace BoolkaEngine::RenderGraphParser {

size_t Antlr4Helper::GetToken(antlr4::ParserRuleContext* context) {
  assert(context);
  assert(dynamic_cast<antlr4::tree::TerminalNode*>(context->children[0]));
  auto* node = static_cast<antlr4::tree::TerminalNode*>(context->children[0]);
  return node->getSymbol()->getType();
}

Variable* Antlr4Helper::GetVariable(const RenderGraph& graph, const char* name,
                                    bool allow_null /*= true*/) {
  if (name == nullptr) {
    assert(allow_null);
    return nullptr;
  }

  const auto variable_iter = graph.variables.find(name);
  if (variable_iter == graph.variables.end()) {
    assert(allow_null);
    return nullptr;
  }

  return variable_iter->second;
}

}  // namespace BoolkaEngine::RenderGraphParser

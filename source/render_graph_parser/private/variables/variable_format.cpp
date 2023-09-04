#include "precompiled_header.h"

#include "variables/variable_format.h"

namespace BoolkaEngine::RenderGraphParser {

VariableFormat ToVariableFormat(size_t /*token*/) {
  throw std::logic_error("Unimplemented");
  return VariableFormat::None;
}

}  // namespace BoolkaEngine::RenderGraphParser

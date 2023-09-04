#pragma once

namespace BoolkaEngine::RenderGraphParser {
enum class VariableFormat {
  // Invalid value
  None = 0,

  Uint,
  Uint2,
  Uint3,
  Uint4,
  Float,
  Float2,
  Float3,
  Float4
};

VariableFormat ToVariableFormat(size_t token);
}  // namespace BoolkaEngine::RenderGraphParser

#pragma once

namespace BoolkaEngine::RenderGraphParser {
enum class ShaderType { VS, AS, MS, PS, CS };

ShaderType ToShaderType(size_t token);
}  // namespace BoolkaEngine::RenderGraphParser

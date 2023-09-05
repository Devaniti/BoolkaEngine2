#pragma once

namespace BoolkaEngine::RenderGraphParser {
enum class VariableUpdateFrequency { Const, Stall, Frame };

VariableUpdateFrequency ToVariableUpdateFrequency(size_t token);
}  // namespace BoolkaEngine::RenderGraphParser

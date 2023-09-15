#pragma once

#include "shader_type.h"

namespace BoolkaEngine::RenderGraphParser {

struct Shader {
  const char* name;
  ShaderType type;
  const char* filename;
  const char* entrypoint;
};

}  // namespace BoolkaEngine::RenderGraphParser

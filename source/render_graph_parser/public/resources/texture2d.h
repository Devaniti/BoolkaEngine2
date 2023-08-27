#pragma once

#include "precompiled_header.h"

#include "texture.h"

namespace BoolkaEngine::RenderGraphParser {
struct Texture2D : public Texture {
  const char* slice_count;
};
}  // namespace BoolkaEngine::RenderGraphParser

#pragma once

#include "precompiled_header.h"

namespace BoolkaEngine::RenderGraphParser {
enum class Usage {
  None = 0,
  // Usage valid for both buffers and textures
  CopySource,
  CopyDest,
  UnorderedAccess,
  // Usage valid only for buffers
  ConstantBuffer,
  IndexBuffer,
  VertexBuffer,
  IndirectCommand,
  AccelerationStructureBuildInput,
  AccelerationStructure,
  ShaderTable,
  // Usage valid only for textures
  SampledImage,
  RenderTarget,
  DepthStencil,
  ShadingRate
};
}  // namespace BoolkaEngine::RenderGraphParser

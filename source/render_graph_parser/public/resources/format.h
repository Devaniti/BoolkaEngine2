#pragma once

#include "precompiled_header.h"

namespace BoolkaEngine::RenderGraphParser {
enum class Format {
  // Only valid for buffers
  None = 0,

  // Formats that are only valid for resources, but not views
  R8,
  R8G8,
  R8G8B8A8,

  R16,
  R16G16,
  R16G16B16A16,

  R32,
  R32G32,
  R32G32B32,
  R32G32B32A32,

  // Formats that are valid for both resources and views
  R8_UNORM,
  R8G8_UNORM,
  R8G8B8A8_UNORM,
  R8_SNORM,
  R8G8_SNORM,
  R8G8B8A8_SNORM,
  R8_UINT,
  R8G8_UINT,
  R8G8B8A8_UINT,
  R8_SINT,
  R8G8_SINT,
  R8G8B8A8_SINT,

  R16_FLOAT,
  R16G16_FLOAT,
  R16G16B16A16_FLOAT,
  R16_UNORM,
  R16G16_UNORM,
  R16G16B16A16_UNORM,
  R16_SNORM,
  R16G16_SNORM,
  R16G16B16A16_SNORM,
  R16_UINT,
  R16G16_UINT,
  R16G16B16A16_UINT,
  R16_SINT,
  R16G16_SINT,
  R16G16B16A16_SINT,

  R32_FLOAT,
  R32G32_FLOAT,
  R32G32B32A32_FLOAT,
  R32_UINT,
  R32G32_UINT,
  R32G32B32A32_UINT,
  R32_SINT,
  R32G32_SINT,
  R32G32B32A32_SINT,
};
}  // namespace BoolkaEngine::RenderGraphParser

#include "precompiled_header.h"

#include "resources/resource_format.h"

#include <render_graph_parser.h>

namespace BoolkaEngine::RenderGraphParser {

ResourceFormat ToResourceFormat(size_t token) {
  switch (token) {
    case render_graph_parser::R8:
      return ResourceFormat::R8;
    case render_graph_parser::R8G8:
      return ResourceFormat::R8G8;
    case render_graph_parser::R8G8B8A8:
      return ResourceFormat::R8G8B8A8;
    case render_graph_parser::R16:
      return ResourceFormat::R16;
    case render_graph_parser::R16G16:
      return ResourceFormat::R16G16;
    case render_graph_parser::R16G16B16A16:
      return ResourceFormat::R16G16B16A16;
    case render_graph_parser::R32:
      return ResourceFormat::R32;
    case render_graph_parser::R32G32:
      return ResourceFormat::R32G32;
    case render_graph_parser::R32G32B32:
      return ResourceFormat::R32G32B32;
    case render_graph_parser::R32G32B32A32:
      return ResourceFormat::R32G32B32A32;
    case render_graph_parser::R8_UNORM:
      return ResourceFormat::R8_UNORM;
    case render_graph_parser::R8G8_UNORM:
      return ResourceFormat::R8G8_UNORM;
    case render_graph_parser::R8G8B8A8_UNORM:
      return ResourceFormat::R8G8B8A8_UNORM;
    case render_graph_parser::R8_SNORM:
      return ResourceFormat::R8_SNORM;
    case render_graph_parser::R8G8_SNORM:
      return ResourceFormat::R8G8_SNORM;
    case render_graph_parser::R8G8B8A8_SNORM:
      return ResourceFormat::R8G8B8A8_SNORM;
    case render_graph_parser::R8_UINT:
      return ResourceFormat::R8_UINT;
    case render_graph_parser::R8G8_UINT:
      return ResourceFormat::R8G8_UINT;
    case render_graph_parser::R8G8B8A8_UINT:
      return ResourceFormat::R8G8B8A8_UINT;
    case render_graph_parser::R8_SINT:
      return ResourceFormat::R8_SINT;
    case render_graph_parser::R8G8_SINT:
      return ResourceFormat::R8G8_SINT;
    case render_graph_parser::R8G8B8A8_SINT:
      return ResourceFormat::R8G8B8A8_SINT;
    case render_graph_parser::R16_FLOAT:
      return ResourceFormat::R16_FLOAT;
    case render_graph_parser::R16G16_FLOAT:
      return ResourceFormat::R16G16_FLOAT;
    case render_graph_parser::R16G16B16A16_FLOAT:
      return ResourceFormat::R16G16B16A16_FLOAT;
    case render_graph_parser::R16_UNORM:
      return ResourceFormat::R16_UNORM;
    case render_graph_parser::R16G16_UNORM:
      return ResourceFormat::R16G16_UNORM;
    case render_graph_parser::R16G16B16A16_UNORM:
      return ResourceFormat::R16G16B16A16_UNORM;
    case render_graph_parser::R16_SNORM:
      return ResourceFormat::R16_SNORM;
    case render_graph_parser::R16G16_SNORM:
      return ResourceFormat::R16G16_SNORM;
    case render_graph_parser::R16G16B16A16_SNORM:
      return ResourceFormat::R16G16B16A16_SNORM;
    case render_graph_parser::R16_UINT:
      return ResourceFormat::R16_UINT;
    case render_graph_parser::R16G16_UINT:
      return ResourceFormat::R16G16_UINT;
    case render_graph_parser::R16G16B16A16_UINT:
      return ResourceFormat::R16G16B16A16_UINT;
    case render_graph_parser::R16_SINT:
      return ResourceFormat::R16_SINT;
    case render_graph_parser::R16G16_SINT:
      return ResourceFormat::R16G16_SINT;
    case render_graph_parser::R16G16B16A16_SINT:
      return ResourceFormat::R16G16B16A16_SINT;
    case render_graph_parser::D32_FLOAT:
      return ResourceFormat::D32_FLOAT;
    case render_graph_parser::R32_FLOAT:
      return ResourceFormat::R32_FLOAT;
    case render_graph_parser::R32G32_FLOAT:
      return ResourceFormat::R32G32_FLOAT;
    case render_graph_parser::R32G32B32A32_FLOAT:
      return ResourceFormat::R32G32B32A32_FLOAT;
    case render_graph_parser::R32_UINT:
      return ResourceFormat::R32_UINT;
    case render_graph_parser::R32G32_UINT:
      return ResourceFormat::R32G32_UINT;
    case render_graph_parser::R32G32B32A32_UINT:
      return ResourceFormat::R32G32B32A32_UINT;
    case render_graph_parser::R32_SINT:
      return ResourceFormat::R32_SINT;
    case render_graph_parser::R32G32_SINT:
      return ResourceFormat::R32G32_SINT;
    case render_graph_parser::R32G32B32A32_SINT:
      return ResourceFormat::R32G32B32A32_SINT;
    default:
      assert(0);
      return ResourceFormat::None;
  }
}

}  // namespace BoolkaEngine::RenderGraphParser

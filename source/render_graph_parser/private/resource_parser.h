#pragma once

#include "precompiled_header.h"

#include "object_container.h"
#include "render_graph_parser.h"
#include "resources/resource.h"

namespace BoolkaEngine::RenderGraphParser {
class ResourceParser {
 public:
  static void Parse(ObjectContainer& container,
                    render_graph_parser::ResourceContext* context);

 private:
  static ResourceType ParseType(
      render_graph_parser::ResourceTypeValueContext* type);
  static Buffer ParseBuffer(
      render_graph_parser::ResourceBodyContext* body);
  static Texture1D ParseTexture1D(
      render_graph_parser::ResourceBodyContext* body);
  static Texture2D ParseTexture2D(
      render_graph_parser::ResourceBodyContext* body);
  static Texture3D ParseTexture3D(
      render_graph_parser::ResourceBodyContext* body);
  static Resource ParseObjectBody(
      render_graph_parser::ResourceBodyContext* body);
};
}  // namespace BoolkaEngine::RenderGraphParser

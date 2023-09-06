#include "precompiled_header.h"

#include "render_graph.h"

namespace BoolkaEngine::RenderGraphParser {

RenderGraph::RenderGraph() : allocator(16 * 1024) {}
RenderGraph::RenderGraph(Allocator::LinearAllocator&& allocator)
    : allocator(std::move(allocator)) {}

}  // namespace BoolkaEngine::RenderGraphParser

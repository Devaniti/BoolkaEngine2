#include "precompiled_header.h"

#include "parser.h"

#include <iostream>

#include <render_graph_lexer.h>
#include <render_graph_parser.h>
#include <render_graph_parserBaseVisitor.h>

#include "file_io.h"
#include "hardware_info.h"
#include "memory_block.h"
#include "parser_context.h"
#include "recursive_directory_iterator.h"
#include "resources/resource_parser.h"
#include "task.h"
#include "task_system.h"
#include "variables/variable_parser.h"

namespace BoolkaEngine::RenderGraphParser {

class ParserVisitor : public render_graph_parserBaseVisitor {
 public:
  ParserVisitor(RenderGraph& graph, ParserContext& parser_context)
      : graph_(graph), parser_context_(parser_context){};

  std::any visitResource(
      render_graph_parser::ResourceContext* context) override {
    ResourceParser::Parse(graph_, parser_context_, context);
    return std::any();
  }

  std::any visitVariable(
      render_graph_parser::VariableContext* context) override {
    VariableParser::Parse(graph_, parser_context_, context);
    return std::any();
  }

 private:
  RenderGraph& graph_;
  ParserContext& parser_context_;
};

RenderGraph* Parser::Parse(const char* source_folder) {
  // HardwareInfo::HardwareInfo::Initialize();
  // TaskSystem ::TaskSystem task_system;
  // TaskSystem::Task iterate_task{.entrypoint = nullptr,
  //                               .user_data = nullptr};
  // task_system.Initialize(&iterate_task, &iterate_task + 1);
  // task_system.Join();

  Allocator::LinearAllocator graph_allocator(16 * 1024);

  auto* result =
      graph_allocator.Emplace<RenderGraph>(std::move(graph_allocator));
  ParserContext parser_context;

  ParseFiles(source_folder, result, parser_context);
  LinkupStep(result);

  return result;
}

void Parser::ParseFiles(const char* source_folder, RenderGraph* graph,
                        ParserContext& parser_context) {
  for (const auto& file :
       Filesystem::RecursiveDirectoryIterator(source_folder)) {
    std::cout << std::endl << file << std::endl << "-------------" << std::endl;

    MemoryManager::MemoryBlock file_data = Filesystem::FileIO::ReadFile(file);
    antlr4::ANTLRInputStream input_stream(
        static_cast<const char*>(file_data.data), file_data.size);
    render_graph_lexer lexer(&input_stream);
    antlr4::CommonTokenStream token_stream(&lexer);
    render_graph_parser parser(&token_stream);
    antlr4::tree::ParseTree* tree = parser.main();

    ParserVisitor visitor(*graph, parser_context);
    visitor.visit(tree);
  }
}

void Parser::LinkupStep(RenderGraph* graph) {}

}  // namespace BoolkaEngine::RenderGraphParser

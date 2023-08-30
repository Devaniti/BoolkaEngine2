#include "precompiled_header.h"

#include "parser.h"

#include <iostream>

#include <render_graph_lexer.h>
#include <render_graph_parser.h>
#include <render_graph_parserBaseVisitor.h>

#include "file_io.h"
#include "hardware_info.h"
#include "memory_block.h"
#include "object_container.h"
#include "recursive_directory_iterator.h"
#include "resource_parser.h"
#include "task.h"
#include "task_system.h"

namespace BoolkaEngine::RenderGraphParser {

class ParserVisitor : public render_graph_parserBaseVisitor {
 public:
  ParserVisitor(ObjectContainer container) : container_(container){};

  virtual std::any visitResource(
      render_graph_parser::ResourceContext* ctx) override {
    ResourceParser::Parse(container_, ctx);
    return std::any();
  }

 private:
  ObjectContainer& container_;
};

RenderGraph* Parser::Parse(const char* source_folder,
                           Allocator::LinearAllocator& /*allocator*/) {
  // HardwareInfo::HardwareInfo::Initialize();
  // TaskSystem ::TaskSystem task_system;
  // TaskSystem::Task iterate_task{.entrypoint = nullptr,
  //                               .user_data = nullptr};
  // task_system.Initialize(&iterate_task, &iterate_task + 1);
  // task_system.Join();

  ObjectContainer container;

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

    ParserVisitor visitor(container);
    visitor.visit(tree);
  }
  return nullptr;
}
}  // namespace BoolkaEngine::RenderGraphParser

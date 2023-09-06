#include "precompiled_header.h"

#include <iostream>

#include "parser.h"

const char* source_folder = nullptr;
const char* dest_folder = nullptr;

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Not enough arguments. Expected 2, Got " << (argc - 1)
              << std::endl;
    return 1;
  }

  source_folder = argv[1];
  dest_folder = argv[2];

  BoolkaEngine::RenderGraphParser::RenderGraph* graph =
      BoolkaEngine::RenderGraphParser::Parser::Parse(source_folder);

  std::cout << "Variables" << std::endl;
  for (const auto& var : graph->variables) {
    std::cout << var.first << " - " << static_cast<int>(var.second->format)
              << " " << static_cast<int>(var.second->update_frequency)
              << std::endl;
  }

  std::cout << "Resources" << std::endl;
  for (const auto& var : graph->resources) {
    std::cout << var.first << " - " << static_cast<int>(var.second->type)
              << std::endl;
  }
}

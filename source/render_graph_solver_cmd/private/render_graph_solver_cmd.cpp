#include "precompiled_header.h"

#include <iostream>

#include "parser.h"

const char* source_folder = nullptr;
const char* dest_folder = nullptr;

using namespace BoolkaEngine;

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Not enough arguments. Expected 2, Got " << (argc - 1)
              << std::endl;
    return 1;
  }

  source_folder = argv[1];
  dest_folder = argv[2];

  Allocator::LinearAllocator allocator(32 * 1024);
  RenderGraphParser::Parser::Parse(source_folder, allocator);
}

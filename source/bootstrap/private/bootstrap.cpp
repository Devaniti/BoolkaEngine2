#include "precompiled_header.h"

#include <iostream>

#include "file_io.h"
#include "linear_allocator.h"
#include "memory_allocator.h"
#include "memory_block.h"
#include "parser.h"
#include "recursive_directory_iterator.h"

void PrintElement(const RGParser::Element* element) {
  std::cout << element->field << " " << element->value << std::endl
            << "{" << std::endl;
  for (RGParser::Element** i = element->subelements; *i != nullptr; ++i) {
    PrintElement(*i);
  }
  std::cout << "}" << std::endl;
}

int main(int argc, char* argv[]) {
  Allocator::LinearAllocator parser_allocator(16 * 1024);
  std::vector<RGParser::Element*> root_elements;
  for (const auto& file :
       Filesystem::RecursiveDirectoryIterator(L"./render_graph/graph")) {
    MemoryManager::MemoryBlock file_data = Filesystem::FileIO::ReadFile(file);
    root_elements.push_back(
        RGParser::Parser::Parse(file_data, parser_allocator));
    MemoryManager::MemoryAllocator::Release(file_data.data);
  }
  for (const auto* root_element : root_elements) {
    PrintElement(root_element);
  }
}

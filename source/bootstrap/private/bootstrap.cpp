#include "precompiled_header.h"

#include <iostream>

#include "file_io.h"
#include "hardware_info.h"
#include "linear_allocator.h"
#include "memory_block.h"
#include "parser.h"
#include "recursive_directory_iterator.h"
#include "task_system.h"

void PrintElement(const RGParser::Element* element) {
  std::cout << element->field << " " << element->value << std::endl
            << "{" << std::endl;
  for (RGParser::Element** i = element->subelements; *i != nullptr; ++i) {
    PrintElement(*i);
  }
  std::cout << "}" << std::endl;
}

std::mutex output_mutex;

void ParseFile(TaskSystem::TaskSystem*, void* user_data) {
  const auto* path = static_cast<const wchar_t*>(user_data);

  Allocator::LinearAllocator parser_allocator(16 * 1024);
  MemoryManager::MemoryBlock file_data = Filesystem::FileIO::ReadFile(path);
  RGParser::Element* root =
      RGParser::Parser::Parse(file_data, parser_allocator);

  {
    std::lock_guard lock(output_mutex);
    std::wcout << path << std::endl;
    PrintElement(root);
  }
}

void IterateFiles(TaskSystem::TaskSystem* task_system, void*) {
  for (const auto& file :
       Filesystem::RecursiveDirectoryIterator(L"./render_graph/graph")) {
    size_t path_length = wcslen(file.c_str());
    auto* path = new wchar_t[path_length + 1];
    memcpy(path, file.c_str(), sizeof(wchar_t) * path_length);
    path[path_length] = L'\0';
    TaskSystem::Task parse_task{.entrypoint = &ParseFile, .user_data = path};
    task_system->AddTask(parse_task);
  }
}

int main(int, char**) {
  HardwareInfo::HardwareInfo::Initialize();
  TaskSystem ::TaskSystem task_system;
  TaskSystem::Task iterate_task{.entrypoint = &IterateFiles,
                                .user_data = nullptr};
  task_system.Initialize(&iterate_task, &iterate_task + 1);
  task_system.Join();
}

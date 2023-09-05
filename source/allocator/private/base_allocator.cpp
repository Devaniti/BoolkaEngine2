#include "precompiled_header.h"

#include "base_allocator.h"

namespace BoolkaEngine::Allocator {

char* BaseAllocator::DuplicateString(const char* src) {
  size_t required_size = std::strlen(src) + 1;
  char* result = static_cast<char*>(Allocate(required_size));

  // Copy together with null terminator
  std::memcpy(result, src, required_size);

  return result;
}

char* BaseAllocator::DuplicateString(const std::string& src) {
  size_t required_size = src.length() + 1;
  char* result = static_cast<char*>(Allocate(required_size));

  // Copy together with null terminator
  std::memcpy(result, src.c_str(), required_size);

  return result;
}

}  // namespace BoolkaEngine::Allocator

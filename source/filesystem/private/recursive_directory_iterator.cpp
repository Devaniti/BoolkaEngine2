#include "precompiled_header.h"

#include "recursive_directory_iterator.h"

namespace BoolkaEngine::Filesystem {

RecursiveDirectoryIterator::RecursiveDirectoryIterator() noexcept
    : iterate_directories_(false), iterate_files_(false) {}

RecursiveDirectoryIterator::RecursiveDirectoryIterator(
    const std::filesystem::path& path, bool iterate_directories /*= false*/,
    bool iterate_files /*= true*/)
    : internal_iterator_(path),
      iterate_directories_(iterate_directories),
      iterate_files_(iterate_files) {
  // We need to have at least something to iterate
  BLK_ASSERT(iterate_directories || iterate_files);

  // First element may be directory, file or something else entirely
  // We need to skip it if it's not what's user requested
  SkipToSuitableElement();
}

const std::filesystem::path& RecursiveDirectoryIterator::operator*()
    const noexcept {
  return internal_iterator_->path();
}

bool RecursiveDirectoryIterator::operator==(
    const RecursiveDirectoryIterator& other) const noexcept {
  return internal_iterator_ == other.internal_iterator_;
}

RecursiveDirectoryIterator& RecursiveDirectoryIterator::operator++() {
  ++internal_iterator_;
  SkipToSuitableElement();
  return *this;
}

void RecursiveDirectoryIterator::SkipToSuitableElement() {
  while (!IsSuitable()) {
    ++internal_iterator_;
  }
}

bool RecursiveDirectoryIterator::IsSuitable() {
  bool is_end =
      internal_iterator_ == std::filesystem::recursive_directory_iterator();
  bool is_directory = !is_end && internal_iterator_->is_directory();
  bool is_file = !is_end && internal_iterator_->is_regular_file();
  return is_end || (iterate_directories_ && is_directory) ||
         (iterate_files_ && is_file);
}

RecursiveDirectoryIterator begin(RecursiveDirectoryIterator iterator) noexcept {
  return iterator;
}

RecursiveDirectoryIterator end(const RecursiveDirectoryIterator&) noexcept {
  return RecursiveDirectoryIterator();
}

}  // namespace BoolkaEngine::Filesystem

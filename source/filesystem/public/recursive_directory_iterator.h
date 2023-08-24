#pragma once

namespace Filesystem {

class RecursiveDirectoryIterator {
 public:
  RecursiveDirectoryIterator() noexcept;
  RecursiveDirectoryIterator(const std::filesystem::path& path,
                             bool iterate_directories = false,
                             bool iterate_files = true);
  ~RecursiveDirectoryIterator() = default;

  RecursiveDirectoryIterator(const RecursiveDirectoryIterator& other) = default;
  RecursiveDirectoryIterator(RecursiveDirectoryIterator&& other) = default;

  RecursiveDirectoryIterator& operator=(
      const RecursiveDirectoryIterator& other) = default;
  RecursiveDirectoryIterator& operator=(RecursiveDirectoryIterator&& other) =
      default;

  [[nodiscard]] const std::filesystem::path& operator*() const noexcept;
  [[nodiscard]] bool operator==(
      const RecursiveDirectoryIterator& other) const noexcept;

  RecursiveDirectoryIterator& operator++();

 private:
  // Each element may be directory, file or something else entirely
  // We need to skip elements that are not requested by user
  void SkipToSuitableElement();

  // Matches current iterator to user's request
  bool IsSuitable();

  std::filesystem::recursive_directory_iterator internal_iterator;
  bool iterate_directories;
  bool iterate_files;
};

// begin/end required for range based for
[[nodiscard]] RecursiveDirectoryIterator begin(
    RecursiveDirectoryIterator iterator) noexcept;
[[nodiscard]] RecursiveDirectoryIterator end(
    RecursiveDirectoryIterator) noexcept;

}  // namespace Filesystem

#pragma once

namespace Filesystem {

class RecursiveDirectoryIterator {
 public:
  RecursiveDirectoryIterator() noexcept;
  explicit RecursiveDirectoryIterator(const std::filesystem::path& path,
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

  std::filesystem::recursive_directory_iterator internal_iterator_;
  bool iterate_directories_;
  bool iterate_files_;
};

// begin/end required for range based for
[[nodiscard]] RecursiveDirectoryIterator begin(
    RecursiveDirectoryIterator iterator) noexcept;
[[nodiscard]] RecursiveDirectoryIterator end(
    const RecursiveDirectoryIterator&) noexcept;

}  // namespace Filesystem

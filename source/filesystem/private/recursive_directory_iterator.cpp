#include "precompiled_header.h"

#include "recursive_directory_iterator.h"

namespace Filesystem
{

	RecursiveDirectoryIterator::RecursiveDirectoryIterator() noexcept
		: iterate_directories(false)
		, iterate_files(false)
	{
	}

	RecursiveDirectoryIterator::RecursiveDirectoryIterator(const std::filesystem::path& path, bool iterate_directories /*= false*/, bool iterate_files /*= true*/)
		: internal_iterator(path)
		, iterate_directories(iterate_directories)
		, iterate_files(iterate_files)
	{
		// We need to have at least something to iterate
		BLK_ASSERT(iterate_directories || iterate_files);

		// First element may be directory, file or something else entirely
		// We need to skip it if it's not what's user requested
		SkipToSuitableElement();
	}

	const std::filesystem::path& RecursiveDirectoryIterator::operator*() const noexcept
	{
		return internal_iterator->path();
	}

	bool RecursiveDirectoryIterator::operator==(const RecursiveDirectoryIterator& other) const noexcept
	{
		return internal_iterator == other.internal_iterator;
	}

	RecursiveDirectoryIterator& RecursiveDirectoryIterator::operator++()
	{
		++internal_iterator;
		SkipToSuitableElement();
		return *this;
	}

	void RecursiveDirectoryIterator::SkipToSuitableElement()
	{
		while (!IsSuitable())
		{
			++internal_iterator;
		}
	}

	bool RecursiveDirectoryIterator::IsSuitable()
	{
		bool is_end = internal_iterator == std::filesystem::recursive_directory_iterator();
		bool is_directory = !is_end && internal_iterator->is_directory();
		bool is_file = !is_end && internal_iterator->is_regular_file();
		return is_end || (iterate_directories && is_directory) || (iterate_files && is_file);
	}

	RecursiveDirectoryIterator begin(RecursiveDirectoryIterator iterator) noexcept
	{
		return iterator;
	}

	RecursiveDirectoryIterator end(RecursiveDirectoryIterator) noexcept
	{
		return RecursiveDirectoryIterator();
	}

}

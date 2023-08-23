#include "precompiled_header.h"

#include "file_io.h"
#include "memory_allocator.h"

namespace Filesystem
{

	MemoryManager::MemoryBlock FileIO::ReadFile(const std::filesystem::path& path)
	{
		MemoryManager::MemoryBlock result{};
		result.size = std::filesystem::file_size(path);
		result.data = MemoryManager::MemoryAllocator::Allocate(result.size);

		std::ifstream input_stream;
		input_stream.open(path, std::ios::binary);
		input_stream.read((char*)result.data, result.size);
		return result;
	}

}

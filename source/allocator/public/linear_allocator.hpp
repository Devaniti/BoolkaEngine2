
namespace Allocator
{
	template <typename T, typename... Args>
	T* LinearAllocator::Emplace(Args... args)
	{
		void* memory = Allocate(sizeof(T));
		return new (memory) T(args...);
	}
}


namespace BoolkaEngine::Allocator {
template <typename T, typename... Args>
T* BaseAllocator::Emplace(Args&&... args) {
  void* memory = Allocate(sizeof(T));
  return new (memory) T(std::forward<Args>(args)...);
}
}  // namespace BoolkaEngine::Allocator

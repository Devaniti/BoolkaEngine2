#pragma once

namespace MemoryManager
{
    class MemoryAPI
    {
    public:
        // Reserves and commits memory
        static void* Allocate(size_t size) noexcept;
        // Only reserves memory
        static void* Reserve(size_t size) noexcept;
        // Only commits memory
        static void Commit(void* adress, size_t size) noexcept;

        // Decommits and unreserves memory
        static void Release(void* adress) noexcept;
        // Only decommits memory
        static void Decommit(void* adress, size_t size) noexcept;
    };
}

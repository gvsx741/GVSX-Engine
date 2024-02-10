#pragma once 

#include <core/memory_manager.h>

namespace gvsx {

    namespace core {

        template<typename T>
        class cAllocator
        {
        public:
            typedef T value_type;

            cAllocator() = default;

            template<class U>
            constexpr cAllocator(const cAllocator<U>&) noexcept {}

            T* allocate(std::size_t size)
            {
                return static_cast<T*>(cMemoryManager::s_Pools->Allocate(sizeof(T) * size));
            }

            void deallocate(T* address, std::size_t size)
            {
                cMemoryManager::s_Pools->Deallocate(address);
            }
        };
    }
}
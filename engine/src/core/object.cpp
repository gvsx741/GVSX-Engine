#pragma once

#include <core/memory_manager.h>

namespace gvsx {

    namespace core {

        void* cObject::operator new(u64 size)
        {
            return cMemoryManager::s_Pools->Allocate(size);
        }

        void cObject::operator delete(void* address)
        {
            cMemoryManager::s_Pools->Deallocate(address);
        }
    }
}
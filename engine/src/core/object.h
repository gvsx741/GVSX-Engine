#pragma once

namespace gvsx {

	namespace core {

        class ENGINE_API cObject
        {
        public:
            void* operator new(u64 size);
            void operator delete(void* address);
        };
	}
}
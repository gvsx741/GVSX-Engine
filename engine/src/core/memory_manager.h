#pragma once 
#include <vector>

namespace gvsx {

	namespace core {

		struct ENGINE_API sAllocation
		{
			u8 FreeFlag = 0;

			u32 Size = 0;
			u32 Used = 0;

			void* Address = nullptr;
		};

		class ENGINE_API cPool
		{
		public:
			void Init(u64 byteSize, u64 allocs, u64 alignment);
			void Release();

			void* Allocate(u64 size);
			bool Deallocate(void* address);

		private:
			void* m_Memory = nullptr;
			void* m_LastAddress = nullptr;
			void* m_MaxAddress = nullptr;

			std::vector<sAllocation> m_Allocs;

			u64 m_ByteSize = 0; 
			u64 m_BytesUsed = 0;

			u64 m_Alignment = 0;
		};

		class ENGINE_API cMemoryPoolStack
		{
		public:
			std::vector<cPool> Pools;

			u64 PoolByteSize = 0;
			u64 PoolAllocs = 0;

			u64 TotalAllocCount = 0;
			u64 TotalFreeCount = 0;

			u64 TotalBytes = 0;

			u64 Alignment = 0;

			cMemoryPoolStack(u64 poolCount, u64 poolByteSize, u64 poolAllocs, u64 alignment);
			~cMemoryPoolStack();

			void* Allocate(u64 size);
			bool Deallocate(void* address);
		};

		class ENGINE_API cMemoryManager
		{
		public:
			static cMemoryPoolStack* s_Pools;

			static void Init();
			static void Release();
		};
	}
}
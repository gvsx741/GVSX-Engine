#pragma once 

namespace gvsx {

	namespace core {

		struct sAllocation
		{
			u32 AllocByteWidth = 0;
			u32 OccupiedByteWidth = 0;
			void* Address = nullptr;
		};

		class ENGINE_API cMemoryPool
		{
		public:
			std::vector<sAllocation> m_Allocs;

			void Init(u64 byteSize, u64 allocs, u64 alignment);
			void Release();

			void* Allocate(u64 size);
			bool Deallocate(void* address);

		private:
			u64 m_ByteSize;
			u64 m_Alignment = 0;

			void* m_Memory;
			void* m_LastAddress;
			void* m_MaxAddress;
		};

		class ENGINE_API cMemoryPoolStack
		{
		public:
			std::vector<cMemoryPool> Pools;

			u64 PoolByteSize = 0;
			u64 PoolAllocs = 0;
			u64 Alignment = 0;

			cMemoryPoolStack(u64 poolCount, u64 poolByteSize, u64 poolAllocs, u64 alignment);
			~cMemoryPoolStack();
		};

		class ENGINE_API cMemoryManager
		{
		public:
			static cMemoryPoolStack* MainPools;

			static void Init();
			static void Reliase();
		};
	}
}
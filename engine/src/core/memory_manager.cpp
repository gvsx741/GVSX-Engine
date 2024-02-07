#include <core/memory_manager.h>

namespace gvsx {

	namespace core {

		cMemoryPoolStack* cMemoryManager::StackPools = nullptr;

		void cMemoryPool::Init(u64 byteSize, u64 allocs, u64 alignment)
		{
			if (alignment == 0) {
				m_Memory = malloc(byteSize);
			}
			else {
				m_Memory = _aligned_malloc(byteSize, alignment);
			}

			m_ByteSize = byteSize;
			m_LastAddress = m_Memory;
			m_MaxAddress = (void*)((u64)m_Memory + byteSize); // carefull
			m_Allocs.reserve(allocs);
			m_Alignment = alignment;
		}

		void cMemoryPool::Release()
		{
			if (m_Alignment == 0) {
				free(m_Memory);
			}
			else {
				_aligned_free(m_Memory);
			}

			m_Allocs.clear();
		}

		void* cMemoryPool::Allocate(u64 size)
		{
			return nullptr;
		}

		bool cMemoryPool::Deallocate(void* address)
		{
			return false;
		}

		cMemoryPoolStack::cMemoryPoolStack(u64 poolCount, u64 poolByteSize, u64 poolAllocs, u64 alignment)
			: PoolByteSize(poolByteSize), PoolAllocs(poolAllocs), Alignment(alignment)
		{
			Pools.reserve(poolCount);

			for (u32 i = 0; i < poolCount; i++)
			{
				cMemoryPool pool;
				pool.Init(poolByteSize, poolAllocs, alignment);
				Pools.emplace_back(pool);
			}
		}

		cMemoryPoolStack::~cMemoryPoolStack()
		{
			for (auto& pool : Pools)
			{
				pool.Release();
			}

			Pools.clear();
		}

		void cMemoryManager::Init()
		{
			u64 memorySize = MEMORY_GB;
			StackPools = new cMemoryPoolStack(1, memorySize, 1000, 0);
		}

		void cMemoryManager::Reliase()
		{
			delete StackPools;
		}
	}
}
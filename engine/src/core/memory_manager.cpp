#include <core/memory_manager.h>

namespace gvsx {

	namespace core {

		cMemoryPoolStack* cMemoryManager::s_Pools;

		void cPool::Init(u64 byteSize, u64 allocs, u64 alignment)
		{
			if (alignment == 0) {
				m_Memory = malloc(byteSize);
			}
			else {
				m_Memory = _aligned_malloc(byteSize, alignment);
			}

			m_ByteSize = byteSize;
			m_LastAddress = m_Memory;
			m_MaxAddress = (void*)((u64)m_Memory + ((u64)byteSize));
			m_Allocs.reserve(allocs);
			m_Alignment = alignment;
		}

		void cPool::Release()
		{
			if (m_Alignment == 0) {
				free(m_Memory);
			}
			else {
				_aligned_free(m_Memory);
			}

			m_Allocs.clear();
		}

		void* cPool::Allocate(u64 size)
		{
			for (auto& alloc : m_Allocs)
			{
				if (alloc.FreeFlag == 1u && alloc.Size >= size)
				{
					alloc.FreeFlag = 255u;
					alloc.Used = size;

					return alloc.Address;
				}

				// New allocation
				if ((alloc.Size - alloc.Used) >= size)
				{
					sAllocation newAlloc;
					newAlloc.FreeFlag = 0u;
					newAlloc.Size = alloc.Size - alloc.Used;
					newAlloc.Used = size;
					newAlloc.Address = (void*)(((u64)alloc.Address) + ((u64)alloc.Used));

					alloc.Size = alloc.Used;

					m_Allocs.emplace_back(newAlloc);

					return newAlloc.Address;
				}
			}

			if (m_LastAddress >= m_MaxAddress) { return nullptr; }

			sAllocation newAlloc;
			newAlloc.FreeFlag = 0u;
			newAlloc.Size = size;
			newAlloc.Used = size;
			newAlloc.Address = m_LastAddress;
			m_Allocs.emplace_back(newAlloc);

			// Update last address
			m_LastAddress = (void*)(((u64)m_LastAddress) + ((u64)size));

			return newAlloc.Address;
		}

		bool cPool::Deallocate(void* address)
		{
			for (auto& alloc : m_Allocs)
			{
				if (alloc.Address == address)
				{
					alloc.FreeFlag = 1u;
					alloc.Used = 0;

					return true;
				}
			}

			return false;
		}

		cMemoryPoolStack::cMemoryPoolStack(u64 poolCount, u64 poolByteSize, u64 poolAllocs, u64 alignment)
			: PoolByteSize(poolByteSize), PoolAllocs(poolAllocs), Alignment(alignment)
		{
			Pools.reserve(poolCount);

			for (u32 i = 0; i < poolCount; i++)
			{
				cPool pool;
				pool.Init(poolByteSize, poolAllocs, alignment);
				Pools.emplace_back(pool);
			}

			TotalBytes = poolCount * poolByteSize;
		}

		cMemoryPoolStack::~cMemoryPoolStack()
		{
			for (auto& pool : Pools)
			{
				pool.Release();
			}

			Pools.clear();
		}

		void* cMemoryPoolStack::Allocate(u64 size)
		{
			void* newAddress = nullptr;

			for (auto& pool : Pools) {
				newAddress = pool.Allocate(size);
				if (newAddress != nullptr) {
					return newAddress;
				}
			}

			u64 poolSize = (size <= PoolByteSize) ? PoolByteSize : size;
			TotalBytes += poolSize;

			cPool newPool;
			newPool.Init(poolSize, PoolAllocs, Alignment);
			newAddress = newPool.Allocate(size);

			Pools.emplace_back(newPool);

			return newAddress;
		}

		bool cMemoryPoolStack::Deallocate(void* address)
		{
			for (auto& pool : Pools) {
				// todo: Need to fix this
				if (pool.Deallocate(address)) {
					return true;
				}
			}
		}

		void cMemoryManager::Init()
		{
			u64 memorySize = MEMORY_GB;
			s_Pools = new cMemoryPoolStack(1, memorySize, 1000, 0);

			LogInfo("cMemoryManager initialized");
		}

		void cMemoryManager::Release()
		{
			delete s_Pools;

			LogInfo("cMemoryManager released");
		}
	}
}
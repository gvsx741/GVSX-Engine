#include <core/memory_manager.h>

namespace gvsx {

	namespace core {

		cMemoryPoolStack* cMemoryManager::MainPools = nullptr;

		void cMemoryPool::Init(u64 byteSize, u64 allocs, u64 alignment)
		{

		}
		void cMemoryPool::Release()
		{

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

		}

		cMemoryPoolStack::~cMemoryPoolStack()
		{

		}

		void cMemoryManager::Init()
		{
			u64 memorySize = MEMORY_GB;
			MainPools = new cMemoryPoolStack(1, memorySize, 1000, 0);
		}

		void cMemoryManager::Reliase()
		{

		}
	}
}
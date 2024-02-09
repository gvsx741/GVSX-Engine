#pragma once 

#include <render/core/context.h>

namespace gvsx {

	namespace render
	{
		enum class eShaderStageType
		{
			NONE = -1,
			VERTEX = 0,
			PIXEL = 1,
			GEOMETRY = 2,
			COMPUTE = 3,
		};

		struct sBlob : public cObject
		{
			void* Instance = nullptr;
			void* ByteCode = nullptr;
			u32 ByteCodeSize = 0;
		};

		struct ENGINE_API sShaderStage
		{
			sShaderStage() = default;
			sShaderStage(eShaderStageType type) : Type(type) {}

			bool Compiled = false;
			
			std::string Profile;
			std::string Source;
			
			eShaderStageType Type;
			sBlob Blob;
		};
	}
}
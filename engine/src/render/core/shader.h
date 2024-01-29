#pragma once 

#include <render/core/context.h>

#include <core/data_types.h>
#include <core/stl.h>
#include <core/logger.h>

namespace gvsx {

	namespace render
	{
		struct sBlob
		{
			void* Instance = nullptr;
			void* ByteCode = nullptr;
			u32 ByteCodeSize = 0;
		};

		enum class eShaderStageType
		{
			NONE = -1,
			VERTEX = 0,
			PIXEL = 1,
			GEOMETRY = 2,
			COMPUTE = 3,
		};

		struct sShaderStage
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
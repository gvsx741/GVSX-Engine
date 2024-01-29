#pragma once 

#include <render/core/context.h>
#include <string>

namespace gvsx {

	namespace render
	{
		struct sBlob
		{
			void* Instance = nullptr;
			void* ByteCode = nullptr;
			unsigned int ByteCodeSize = 0;
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
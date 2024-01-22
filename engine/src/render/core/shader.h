#pragma once 

#include <render/core/context.h>

namespace gvsx {

	namespace render
	{
		enum class eShaderType
		{
			NONE = -1,
			VERTEX = 0,
			PIXEL = 1
		};

		class cShader 
		{
			eShaderType type;
			ID3D10Blob *shader;
		};
	}
}
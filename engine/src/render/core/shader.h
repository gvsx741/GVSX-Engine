#pragma once 

#include <render/core/context.h>

namespace gvsx {

	namespace render
	{
		enum class eShaderType
		{
			NONE = -1,
			VERTEX = 0,
			PIXEL = 1,
			GEOMETRY = 2,
			COMPUTE = 3,
		};

		class cShader
		{
		public:
			cShader() {}
			cShader(eShaderType type) : Type(type) {}

			eShaderType Type;
			ID3D10Blob *Blob;
		};
	}
}
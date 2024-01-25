#pragma once 
#include <render/core/shader.h>
#include <unordered_map>

namespace gvsx {

	namespace render
	{
		class cShaderManager
		{
		public:

			static cShader* LoadShader(const char* filename, eShaderType type);
			static void SetShader(const char* filename);

		private:

			static std::unordered_map<const char*, cShader*> m_Shaders;
		
		};
	}
}
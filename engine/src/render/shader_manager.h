#pragma once 
#include <render/core/shader.h>

namespace gvsx {

	namespace render
	{
		class ENGINE_API cShaderManager : public cObject
		{
		public:
			static sShaderStage* CreateStageFromFile(const char* filepath, eShaderStageType type);

		private:
			static void CompileShaderStage(sShaderStage& stage);
			static void CreateShaderStage(sShaderStage& stage);

		private:
			static unordered_map<const char*, sShaderStage*> s_Stages;
		
		};
	}
}
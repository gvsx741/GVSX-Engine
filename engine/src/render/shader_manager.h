#pragma once 
#include <render/core/shader.h>
#include <unordered_map> //temporarily

namespace gvsx {

	namespace render
	{
		class cShaderManager
		{
		public:
			static sShaderStage* CreateStageFromFile(const char* filepath, eShaderStageType type);

		private:
			static void CompileShaderStage(sShaderStage& stage);
			static void CreateShaderStage(sShaderStage& stage);

		private:
			static std::unordered_map<const char*, sShaderStage*> s_Stages;
		
		};
	}
}
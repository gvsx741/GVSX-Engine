#include <render/shader_manager.h>
#include <render/core/context.h>
#include <core/logger.h>

namespace gvsx {

	namespace render
	{
		cShader* cShaderManager::LoadShader(const char* filepath, eShaderType type)
		{
			auto shader_it = m_Shaders.find(filepath);

			if(shader_it != m_Shaders.end()) {
				return shader_it->second;
			}

			cShader* shader = new cShader(type);

			switch (type)
			{
			case eShaderType::VERTEX:
				D3DCompileFromFile(LPCWSTR(filepath), 0, 0, "default.vs", "vs_5_1", 0, 0, &shader->Blob, 0);
				break;

			case eShaderType::PIXEL:
				D3DCompileFromFile(LPCWSTR(filepath), 0, 0, "default.ps", "ps_5_1", 0, 0, &shader->Blob, 0);
				break;
				
			default:
				core::LogWarn("Undefined shader type");
				break;
			}

			return shader;
		}

		void cShaderManager::SetShader(const char* filename)
		{

		}
	}
}
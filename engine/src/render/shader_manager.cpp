#include <render/shader_manager.h>
#include <render/core/context.h>
#include <core/logger.h>

namespace gvsx {

	namespace render
	{
		using namespace core;
		using namespace context;

		std::unordered_map<const char*, sShaderStage*> cShaderManager::s_Stages = {};

		sShaderStage* cShaderManager::CreateStageFromFile(const char* filepath, eShaderStageType type)
		{
			if(s_Stages.find(filepath) != s_Stages.end()) {
				return s_Stages.at(filepath);
			}

			sShaderStage* stage = new sShaderStage(type);

			return stage;
		}

		void cShaderManager::CompileShaderStage(sShaderStage& stage)
		{
			if (stage.Compiled) {
				return;
			}

			ID3DBlob* shaderBlob = nullptr;
			ID3DBlob* errorBlob = nullptr;

			switch (stage.Type)
			{
			case eShaderStageType::VERTEX:
				D3DCompile(stage.Source.c_str(), stage.Source.length(), 0, 0, 0, "vs_main", stage.Profile.c_str(), 0, 0, &shaderBlob, &errorBlob);
				break;

			case eShaderStageType::PIXEL:
				D3DCompile(stage.Source.c_str(), stage.Source.length(), 0, 0, 0, "ps_main", stage.Profile.c_str(), 0, 0, &shaderBlob, &errorBlob);
				break;

			default:
				LogError("Undefined shader type");
				break;
			}

			if (shaderBlob != nullptr) {
				stage.Compiled = true;
				stage.Blob.Instance= shaderBlob;
				stage.Blob.ByteCode = shaderBlob->GetBufferPointer();
				stage.Blob.ByteCodeSize = shaderBlob->GetBufferSize();
			}
		}

		void cShaderManager::CreateShaderStage(sShaderStage& stage)
		{
			sBlob blob = stage.Blob;

			if (blob.Instance != nullptr) {

				switch (stage.Type) {

				case eShaderStageType::VERTEX:
					Device->CreateVertexShader(
						blob.ByteCode,
						blob.ByteCodeSize,
						nullptr,
						(ID3D11VertexShader**)&blob.Instance
					);
					break;

				case eShaderStageType::PIXEL:
					Device->CreatePixelShader(
						blob.ByteCode,
						blob.ByteCodeSize,
						nullptr,
						(ID3D11PixelShader**)&blob.Instance
					);
					break;
				}
			}
		}

	}
}
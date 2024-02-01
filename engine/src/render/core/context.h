#pragma once

#include <d3d11.h>
#pragma comment (lib, "d3d11.lib")

#include <d3dcompiler.h>
#pragma comment (lib, "D3DCompiler.lib")


namespace gvsx {

	namespace render {

		namespace context {

			static ID3D11Device* Device;
			static ID3D11DeviceContext* DeviceContext;
			static IDXGISwapChain* SwapChain;
			static ID3D11RenderTargetView* BackBuffer;

			void ENGINE_API InitDX11();
			void ENGINE_API FreeDX11();

			void ENGINE_API CreateSwapChain();

			void ENGINE_API SetViewport(int TopLeftX, int TopLeftY, int Width, int Height);

			void ENGINE_API Render();
		}
	}
}
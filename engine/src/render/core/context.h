#pragma once

#include <d3d11.h>
#pragma comment (lib, "d3d11.lib")

namespace gvsx {

	namespace render {

		namespace context {

			static ID3D11Device* Device;
			static ID3D11DeviceContext* DeviceContext;
			static IDXGISwapChain* SwapChain;
			static ID3D11RenderTargetView* BackBuffer;

			void InitDX11();
			void FreeDX11();

			void CreateSwapChain();

			void SetViewport(int TopLeftX, int TopLeftY, int Width, int Height);

			void Render();
		}
	}
}
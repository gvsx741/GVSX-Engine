#pragma once

#include <d3d11.h>
#pragma comment (lib, "d3d11.lib")

#include <window/window_manager.h>

namespace gvsx {

	namespace render {

		namespace context {

			static ID3D11Device* pDevice;
			static ID3D11DeviceContext* pDeviceContext;
			static IDXGISwapChain* pSwapChain;
			static ID3D11RenderTargetView* pBackBuffer;

			void InitDX11();
			void FreeDX11();

			void CreateSwapChain();

			void SetViewport(int TopLeftX, int TopLeftY, int Width, int Height);

			void Render();
		}
	}
}
#pragma once

#include <d3d11.h>
#pragma comment (lib, "d3d11.lib")

namespace gvsx {

	namespace render {

		namespace context {

			static IDXGISwapChain* pSwapChain;
			static ID3D11Device* pDevice;
			static ID3D11DeviceContext* pDeviceContext;
			static ID3D11RenderTargetView* pBackBuffer;

			void InitDX11(HWND hWnd);
			void Render();
			void FreeDX11();
		}
	}
}
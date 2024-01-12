#include <render/context.h>

namespace gvsx {

	namespace render {

		namespace context {

            void InitDX11(HWND hWnd)
            {
                // create a struct to hold information about the swap chain
                DXGI_SWAP_CHAIN_DESC SwapChainDesc;

                // clear out the struct for use
                ZeroMemory(&SwapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));

                // fill the swap chain description struct
                SwapChainDesc.BufferCount = 1;                                    // one back buffer
                SwapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;     // use 32-bit color
                SwapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;      // how swap chain is to be used
                SwapChainDesc.OutputWindow = hWnd;                                // the window to be used
                SwapChainDesc.SampleDesc.Count = 4;                               // how many multisamples
                SwapChainDesc.Windowed = TRUE;                                    // windowed/full-screen mode

                // create a device, device context and swap chain using the information in the scd struct
                D3D11CreateDeviceAndSwapChain(NULL,
                    D3D_DRIVER_TYPE_HARDWARE,
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    D3D11_SDK_VERSION,
                    &SwapChainDesc,
                    &pSwapChain,
                    &pDevice,
                    NULL,
                    &pDeviceContext);
            }

            void FreeDX11()
            {
                // close and release all existing COM objects
                pSwapChain->Release();
                pDevice->Release();
                pDeviceContext->Release();
            }
		}
	}
}
#include <render/context.h>

#include <glm/glm.hpp>

namespace gvsx {

	namespace render {

		namespace context {

            float color[]{ 1.0f, 1.0f, 1.0f, 1.0f };

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

                // get the address of the back buffer
                ID3D11Texture2D* pAddressBackBuffer;
                pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pAddressBackBuffer);

                // use the back buffer address to create the render target
                pDevice->CreateRenderTargetView(pAddressBackBuffer, NULL, &pBackBuffer);
                pAddressBackBuffer->Release();

                // set the render target as the back buffer
                pDeviceContext->OMSetRenderTargets(1, &pBackBuffer, NULL);

                // Set the viewport
                D3D11_VIEWPORT viewport;
                ZeroMemory(&viewport, sizeof(D3D11_VIEWPORT));

                viewport.TopLeftX = 0;
                viewport.TopLeftY = 0;
                viewport.Width = 640;
                viewport.Height = 640;

                pDeviceContext->RSSetViewports(1, &viewport);
            }

            void Render()
            {
                pDeviceContext->ClearRenderTargetView(pBackBuffer, color);
                pSwapChain->Present(0, 0);
            }

            void FreeDX11()
            {
                pSwapChain->Release();
                pBackBuffer->Release();
                pDevice->Release();
                pDeviceContext->Release();
            }
		}
	}
}
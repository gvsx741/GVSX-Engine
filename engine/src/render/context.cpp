#include <render/context.h>

#include <window/window_manager.h>

#include <glm/glm.hpp>

namespace gvsx {

	namespace render {

		namespace context {

            using namespace window;

            float color[]{ 0.0f, 0.2f, 0.4f, 1.0f };

            void InitDX11()
            {
                CreateSwapChain();

                ID3D11Texture2D* pResource;
                SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pResource);

                Device->CreateRenderTargetView(pResource, NULL, &BackBuffer);
                pResource->Release();

                DeviceContext->OMSetRenderTargets(1, &BackBuffer, NULL);

                auto winDesc = cWindowManager::GetDesc();
                SetViewport(winDesc.TopLeftX, winDesc.TopLeftY, winDesc.Width, winDesc.Height);
            }

            void FreeDX11()
            {
                SwapChain->Release();
                BackBuffer->Release();
                Device->Release();
                DeviceContext->Release();
            }

            void Render()
            {
                DeviceContext->ClearRenderTargetView(BackBuffer, color);
                SwapChain->Present(0, 0);
            }

            void CreateSwapChain()
            {
                DXGI_MODE_DESC BufferDesc{};

                BufferDesc.Width = cWindowManager::GetWidth();
                BufferDesc.Height = cWindowManager::GetHeight();
                BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
                BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
                BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
                
                DXGI_SWAP_CHAIN_DESC SwapChainDesc{};

                SwapChainDesc.BufferCount = 1;                                    
                SwapChainDesc.BufferDesc = BufferDesc;
                SwapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;      
                SwapChainDesc.OutputWindow = (HWND)cWindowManager::GetWin32Instance();                                
                SwapChainDesc.SampleDesc.Count = 4;                               
                SwapChainDesc.Windowed = !cWindowManager::isFullScreen();;

                D3D11CreateDeviceAndSwapChain(NULL,
                    D3D_DRIVER_TYPE_HARDWARE,
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    D3D11_SDK_VERSION,
                    &SwapChainDesc,
                    &SwapChain,
                    &Device,
                    NULL,
                    &DeviceContext);
            }

            void SetViewport(int TopLeftX, int TopLeftY, int Width, int Height)
            {
                D3D11_VIEWPORT viewport{};

                viewport.TopLeftX = TopLeftX;
                viewport.TopLeftY = TopLeftX;
                viewport.Width = Width;
                viewport.Height = Height;

                DeviceContext->RSSetViewports(1, &viewport);
            }
		}
	}
}
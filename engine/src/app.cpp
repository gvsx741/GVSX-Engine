#include <app.h>

namespace gvsx {

	using namespace window;
	using namespace render;

	void cApp::Init()
	{
		cWindowManager::Init();
		cWindowManager::InitWindow(sWindowDesc());
	}

	void cApp::Free()
	{
		cWindowManager::Free();
	}

	void cApp::Run()
	{
		cRenderSystem RenderSystem;

		RenderSystem.Init((HWND)cWindowManager::GetWin32Window());

		while(!cWindowManager::CheckClosed())
		{
			RenderSystem.Update();
			cWindowManager::SwapBuffers();
			cWindowManager::CheckEvents();
		}
	}

}
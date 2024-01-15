#include <app.h>

#include <core/logger.h>

namespace gvsx {

	using namespace core;
	using namespace window;
	using namespace render;

	void cApp::Init()
	{
		LogInfo("Application initialization");

		cWindowManager::Init();
		cWindowManager::InitWindow(sWindowDesc());

		LogInfo("Application initialized");
	}

	void cApp::Free()
	{
		cWindowManager::Free();
		LogInfo("Application free");
	}

	void cApp::Run()
	{
		cRenderSystem RenderSystem;

		RenderSystem.Init();

		while(!cWindowManager::isClosed())
		{
			RenderSystem.Update();

			//cWindowManager::SwapBuffers();
			cWindowManager::CheckEvents();
		}

		RenderSystem.Free();
	}

}
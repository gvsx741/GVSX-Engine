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
		while(!cWindowManager::CheckClosed())
		{
			cWindowManager::SwapBuffers();
			cWindowManager::CheckEvents();
		}
	}

}
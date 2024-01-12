#include <app.h>

#include <iostream>

namespace gvsx {

	//using namespace render;
	using namespace window;

	void cApp::Init()
	{
		cWindowManager::Init();
		cWindowManager::InitWindow(sWindowDescription());
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
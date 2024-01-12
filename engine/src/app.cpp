#include <app.h>

#include <iostream>

namespace gvsx {

	//using namespace render;

	void cApp::Init()
	{
		cWindowManager::Init();
		cWindowManager::Create(640, 640, "GVSX_WINDOW");
		cWindowManager::MakeCurrent(cWindowManager::GetWindow());

	}

	void cApp::Free()
	{
		cWindowManager::Free();
	}

	void cApp::Run()
	{
		while(!cWindowManager::CheckClosed())
		{
			cWindowManager::SwapBuffer(cWindowManager::GetWindow());
			cWindowManager::CheckEvents();
		}

		cWindowManager::Destroy(cWindowManager::GetWindow());
	}

}
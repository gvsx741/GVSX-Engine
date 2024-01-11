#include <app.h>
#include <iostream>

namespace gvsx {

	void cApp::Init()
	{
		cWindowManager::Init();
	}

	void cApp::Free()
	{
		cWindowManager::Free();
	}

	void cApp::Run()
	{

		window = cWindowManager::Create(640, 640, "GVSX_WINDOW");

		cWindowManager::MakeCurrent(window);
		
		while(!cWindowManager::CheckClosed(window))
		{
			cWindowManager::SwapBuffer(window);
			cWindowManager::CheckEvents();
		}

		cWindowManager::Destroy(window);
	}

}
#include <core/app.h>

#include <render/render_system.h>
#include <window/window_manager.h>

namespace gvsx {

	namespace core {

		using namespace window;
		using namespace render;

		void cApp::Run()
		{
			Init();

			m_RenderSystem = new cRenderSystem();

			while(!cWindowManager::isClosed())
			{
				m_RenderSystem->Update();

				//cWindowManager::SwapBuffers();
				cWindowManager::CheckEvents();
			}

			Free();
		}

		void cApp::Init()
		{
			LogInfo("Application initialization");
			
			cWindowManager::Init();
			cWindowManager::InitWindow(sWindowDesc());

			m_RenderSystem->Init();	

			LogInfo("Application initialized");
		}

		void cApp::Free()
		{
			m_RenderSystem->Free();

			cWindowManager::Free();

			LogInfo("Application free");
		}
	}
}
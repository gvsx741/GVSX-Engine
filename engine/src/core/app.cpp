#include <core/app.h>

#include <render/render_system.h>
#include <window/window_manager.h>

#include <render/core/shader.h>

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

			Reliase();
		}

		void cApp::Init()
		{
			LogInfo("Application initialization");
			
			cMemoryManager::Init();

			cWindowManager::Init();
			cWindowManager::InitWindow(sWindowDesc());

			m_RenderSystem->Init();	

			LogInfo("Application initialized");
		}

		void cApp::Reliase()
		{
			m_RenderSystem->Reliase();

			cWindowManager::Reliase();

			cMemoryManager::Reliase();

			LogInfo("Application free");
		}
	}
}
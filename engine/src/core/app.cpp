#include <core/app.h>

#include <window/window_manager.h>
#include <render/shader_manager.h>

#include <render/render_system.h>

namespace gvsx {

	namespace core {

		using namespace window;
		using namespace render;

		cApp::cApp()
		{
			LogInfo("Application initialization");
			
			cWindowManager::Init();
			cWindowManager::InitWindow(sWindowDesc());
			cShaderManager::Init();

			m_RenderSystem = new cRenderSystem();

			LogInfo("Application initialized");
		}

		cApp::~cApp()
		{
			LogInfo("Application releasing");
			
			delete m_RenderSystem;

			cShaderManager::Release();
			cWindowManager::ReleaseWindow();
			cWindowManager::Release();

			LogInfo("Application released");
		}

		void cApp::Run()
		{
			while(!cWindowManager::isClosed())
			{
				glfwPollEvents();

				m_RenderSystem->Update();

				//cWindowManager::SwapBuffers();
				cWindowManager::CheckEvents();
			}
		}
	}
}
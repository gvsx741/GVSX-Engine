#include <window/window_manager.h>

namespace gvsx {

	namespace window {

		GLFWmonitor* cWindowManager::m_pMainMonitor = nullptr;
		GLFWwindow* cWindowManager::m_pWindow = nullptr;
		sWindowDesc cWindowManager::m_WindowDesc;

		void cWindowManager::Init()
		{
			if (!glfwInit()) {
				std::cout << "GLFW is not init" << std::endl;
			}

			m_pMainMonitor = glfwGetPrimaryMonitor();
		}

		void cWindowManager::Free()
		{
			glfwTerminate();
		}

		void cWindowManager::InitWindow(sWindowDesc desc)
		{
			m_WindowDesc = desc;

			m_pWindow = glfwCreateWindow(desc.Width, desc.Height, desc.Title, NULL, NULL);

			if (!m_pWindow)
			{
				std::cout << "Window is not created" << std::endl;
			}

			glfwMakeContextCurrent(m_pWindow);
		}

		void cWindowManager::FreeWindow()
		{
			if (m_pWindow != nullptr) {
				glfwDestroyWindow(m_pWindow);
			}
		}

		GLFWwindow* cWindowManager::GetInstance()
		{
			return m_pWindow;
		}

		void* cWindowManager::GetWin32Instance()
		{
			return glfwGetWin32Window(m_pWindow);
		}

		const sWindowDesc& cWindowManager::GetDesc()
		{
			return m_WindowDesc;
		}

		bool cWindowManager::isClosed()
		{
			return glfwWindowShouldClose(m_pWindow);
		}

		bool cWindowManager::isFullScreen()
		{
			return m_WindowDesc.Fullscreen;
		}

		int cWindowManager::GetWidth()
		{
			return m_WindowDesc.Width;
		}

		int cWindowManager::GetHeight()
		{
			return m_WindowDesc.Height;
		}

		int cWindowManager::GetTopLeftX()
		{
			return m_WindowDesc.TopLeftX;
		}

		int cWindowManager::GetTopLeftY()
		{
			return m_WindowDesc.TopLeftY;
		}

		void cWindowManager::SwapBuffers()
		{
			glfwSwapBuffers(m_pWindow);
		}

		void cWindowManager::CheckEvents()
		{
			glfwPollEvents();
		}
	}
};
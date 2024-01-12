#include <window/window_manager.h>

namespace gvsx {

	namespace window {

		GLFWwindow* cWindowManager::m_pWindow = nullptr;
		sWindowDesc cWindowManager::m_WindowDesc;

		void cWindowManager::Init()
		{
			if (!glfwInit()) {
				std::cout << "GLFW is not init" << std::endl;
			}
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

		void cWindowManager::CheckEvents()
		{
			glfwPollEvents();
		}

		void cWindowManager::SwapBuffers()
		{
			glfwSwapBuffers(m_pWindow);
		}

		GLFWwindow* cWindowManager::GetWindow()
		{
			return m_pWindow;
		}

		void* cWindowManager::GetWin32Window()
		{
			return glfwGetWin32Window(m_pWindow);
		}

		const sWindowDesc& cWindowManager::GetDescription()
		{
			return m_WindowDesc;
		}

		bool cWindowManager::CheckClosed()
		{
			return glfwWindowShouldClose(m_pWindow);
		}
	}
};
#include <window/window_manager.h>

namespace gvsx {

	namespace window {

		GLFWwindow* cWindowManager::m_Window = nullptr;

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

		void cWindowManager::InitWindow(sWindowDescription desc)
		{
			m_Window = glfwCreateWindow(desc.Width, desc.Height, desc.Title, NULL, NULL);

			if (!m_Window)
			{
				std::cout << "Window is not created" << std::endl;
			}

			glfwMakeContextCurrent(m_Window);
		}

		void cWindowManager::FreeWindow()
		{
			if (m_Window != nullptr) {
				glfwDestroyWindow(m_Window);
			}
		}

		void cWindowManager::CheckEvents()
		{
			glfwPollEvents();
		}

		void cWindowManager::SwapBuffers()
		{
			glfwSwapBuffers(m_Window);
		}

		GLFWwindow* cWindowManager::GetWindow()
		{
			return m_Window;
		}

		void* cWindowManager::GetWin32Window()
		{
			return glfwGetWin32Window(m_Window);
		}

		bool cWindowManager::CheckClosed()
		{
			return glfwWindowShouldClose(m_Window);
		}
	}
};
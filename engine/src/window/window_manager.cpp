#include <window/window_manager.h>

namespace gvsx {

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

	void cWindowManager::Create(int width, int height, const char* title)
	{
		m_Window = glfwCreateWindow(width, height, title, NULL, NULL);
		
		if (!m_Window)
		{
			std::cout << "Window is not created" << std::endl;
		}
	}

	void cWindowManager::Destroy(GLFWwindow* window)
	{
		glfwDestroyWindow(window);
	}

	void cWindowManager::MakeCurrent(GLFWwindow* window)
	{
		glfwMakeContextCurrent(window);
	}

	void cWindowManager::CheckEvents()
	{
		glfwPollEvents();
	}

	void cWindowManager::SwapBuffer(GLFWwindow* window)
	{
		glfwSwapBuffers(window);
	}

	GLFWwindow* cWindowManager::GetWindow()
	{
		return m_Window;
	}

	void* cWindowManager::GetWindow32()
	{
		return glfwGetWin32Window(m_Window);
	}

	bool cWindowManager::CheckClosed()
	{
		return glfwWindowShouldClose(m_Window);
	}
};
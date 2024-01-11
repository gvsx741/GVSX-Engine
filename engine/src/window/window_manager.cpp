#include <window/window_manager.h>
#include <iostream>

namespace gvsx {

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

	GLFWwindow* cWindowManager::Create(int width, int height, const char* title)
	{
		GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
		
		if (!window)
		{
			std::cout << "Window is not created" << std::endl;
		}

		return window;
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

	bool cWindowManager::CheckClosed(GLFWwindow* window)
	{
		return glfwWindowShouldClose(window);
	}
};
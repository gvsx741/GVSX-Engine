#pragma once

#define GLFW_EXPOSE_NATIVE_WIN32

#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#include <iostream>

namespace gvsx {

	class cWindowManager
	{
	public:
		static void Init();
		static void Free();

		static void Create(int width, int height, const char* title);
		static void Destroy(GLFWwindow* window);

		static GLFWwindow* GetWindow();
		static void* GetWindow32();
		static bool CheckClosed();
		
		static void MakeCurrent(GLFWwindow* window);
		static void SwapBuffer(GLFWwindow* window);
		static void CheckEvents();

	private:
		static GLFWwindow* m_Window;
	};

};
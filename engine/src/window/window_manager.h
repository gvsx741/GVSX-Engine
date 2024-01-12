#pragma once

#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#include <iostream>

namespace gvsx {

	namespace window {

		struct sWindowDescription
		{
			const char* Title = "Window";

			int Width = 640;
			int Height = 640;

			bool VSync = false;
			bool Fullscreen = false;
		};

		class cWindowManager
		{
		public:
			static void Init();
			static void Free();

			static void InitWindow(sWindowDescription desc);
			static void FreeWindow();

			static GLFWwindow* GetWindow();
			static void* GetWin32Window();

			static bool CheckClosed();

			static void SwapBuffers();
			static void CheckEvents();

		private:
			static GLFWwindow* m_Window;
		};

	}
};
#pragma once

#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#include <iostream>

namespace gvsx {

	namespace window {

		struct sWindowDesc
		{
			const char* Title = "Window";

			int TopLeftX = 0;
			int TopLeftY = 0;

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

			static void InitWindow(sWindowDesc desc);
			static void FreeWindow();

			static GLFWwindow* GetInstance();
			static void* GetWin32Instance();
			static const sWindowDesc& GetDesc();

			static bool isClosed();
			static bool isFullScreen();

			static int GetWidth();
			static int GetHeight();
			static int GetTopLeftX();
			static int GetTopLeftY();

			static void SwapBuffers();
			static void CheckEvents();

		private:
			static GLFWmonitor* m_pMainMonitor;
			static GLFWwindow* m_pWindow;
			static sWindowDesc m_WindowDesc;
		};

	}
};
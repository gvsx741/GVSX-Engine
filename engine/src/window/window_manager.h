#pragma once

#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

namespace gvsx {

	namespace window {

		struct ENGINE_API sWindowDesc : public cObject
		{
			sWindowDesc() {}
			sWindowDesc(const char* title, s32 topLeftX, s32 topLeftY, s32 width, s32 height, bool fullscreen)
				: Title(title), TopLeftX(topLeftX), TopLeftY(topLeftY), Width(width), Height(height), Fullscreen(fullscreen) {
			}

			string name = "window";

			const char* Title = "Window";

			s32 TopLeftX = 0;
			s32 TopLeftY = 0;

			s32 Width = 640;
			s32 Height = 640;

			//bool VSync = false;
			bool Fullscreen = false;
		};

		class ENGINE_API cWindowManager : public cObject
		{
		public:
			static void Init();
			static void Release();

			static void InitWindow(sWindowDesc desc);
			static void ReleaseWindow();

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
			static GLFWmonitor* s_MainMonitor;
			static GLFWwindow* s_Window;
			static sWindowDesc s_WindowDesc;
		};

	}
};
#include <window/window_manager.h>

#include <input/mouse_input.h>
#include <input/keyboard_input.h>

namespace gvsx {

	namespace window {

		using namespace input;

		GLFWmonitor* cWindowManager::s_MainMonitor = nullptr;
		GLFWwindow* cWindowManager::s_Window = nullptr;
		sWindowDesc cWindowManager::s_WindowDesc;

		void cWindowManager::Init()
		{
			if (!glfwInit()) {
				LogError("GLFW is not init");
			}

			s_MainMonitor = glfwGetPrimaryMonitor();

			LogInfo("cWindowManager initialized");
		}

		void cWindowManager::Release()
		{
			glfwTerminate();
			LogInfo("cWindowManager released");
		}

		void cWindowManager::InitWindow(sWindowDesc desc)
		{
			s_WindowDesc = desc;

			s_Window = glfwCreateWindow(desc.Width, desc.Height, desc.Title.c_str(), NULL, NULL);

			if (!s_Window)
			{
				LogError("Window is not created");
			}

			glfwMakeContextCurrent(s_Window);

			glfwSetKeyCallback(s_Window, KeyCallback);
			glfwSetCursorPosCallback(s_Window, CursorPositionCallback);

			LogInfo("Main window initialized");
		}

		void cWindowManager::ReleaseWindow()
		{
			if (s_Window != nullptr) {
				glfwDestroyWindow(s_Window);
				LogInfo("Main window released");
			}
		}

		GLFWwindow* cWindowManager::GetInstance()
		{
			return s_Window;
		}

		void* cWindowManager::GetWin32Instance()
		{
			return glfwGetWin32Window(s_Window);
		}

		const sWindowDesc& cWindowManager::GetDesc()
		{
			return s_WindowDesc;
		}

		bool cWindowManager::isClosed()
		{
			return glfwWindowShouldClose(s_Window);
		}

		bool cWindowManager::isFullScreen()
		{
			return s_WindowDesc.Fullscreen;
		}

		int cWindowManager::GetWidth()
		{
			return s_WindowDesc.Width;
		}

		int cWindowManager::GetHeight()
		{
			return s_WindowDesc.Height;
		}

		int cWindowManager::GetTopLeftX()
		{
			return s_WindowDesc.TopLeftX;
		}

		int cWindowManager::GetTopLeftY()
		{
			return s_WindowDesc.TopLeftY;
		}

		void cWindowManager::SwapBuffers()
		{
			glfwSwapBuffers(s_Window);
		}

		void cWindowManager::CheckEvents()
		{
			glfwPollEvents();
		}
	}
};
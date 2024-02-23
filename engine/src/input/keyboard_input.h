#pragma once

#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

namespace gvsx {

	namespace input {

		void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

	}
}
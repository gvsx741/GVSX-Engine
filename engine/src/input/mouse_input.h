#pragma once

#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

namespace gvsx {

	namespace input {

		void CursorPositionCallback(GLFWwindow* window, double xpos, double ypos);

	}
}
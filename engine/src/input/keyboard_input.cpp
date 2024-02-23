#include <input/keyboard_input.h>

#include <window/window_manager.h>

namespace gvsx {

	namespace input {

		bool left_alt = true;

		void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			if (action == GLFW_PRESS || action == GLFW_REPEAT) {

				if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
				{
					LogInfo("A");
					LogInfo("D");
				}

				if (glfwGetKey(window, GLFW_KEY_LEFT_ALT) == GLFW_PRESS)
				{
					if(left_alt) { glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); }
					else { glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL); }

					left_alt = !left_alt;
				}

				if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
					glfwSetWindowShouldClose(window, GL_TRUE);
				}
			}
		}
	}
}
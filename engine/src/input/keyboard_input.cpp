#include <input/keyboard_input.h>

namespace gvsx {

	namespace input {

		void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			if (action == GLFW_PRESS || action == GLFW_REPEAT) {

				if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
				{
					LogInfo("A");
					LogInfo("D");
				}
			}
		}
	}
}
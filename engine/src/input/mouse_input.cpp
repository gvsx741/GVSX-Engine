#include <input\mouse_input.h>
#include <sstream>

namespace gvsx {

	namespace input {

		void CursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
		{
			std::ostringstream stringStream;

			stringStream << "x: " << xpos << " | y: " << ypos;;

			std::string s = stringStream.str();

			LogInfo(s.c_str());
		}
	}
}

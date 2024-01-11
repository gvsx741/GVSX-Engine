#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace gvsx {

	class cWindowManager
	{
	public:
		
		static void Init();
		static void Free();

		static GLFWwindow* Create(int width, int height, const char* title);
		static void Destroy(GLFWwindow* window);

		static bool CheckClosed(GLFWwindow* window);
		
		static void MakeCurrent(GLFWwindow* window);
		static void SwapBuffer(GLFWwindow* window);
		static void CheckEvents();
	};

};
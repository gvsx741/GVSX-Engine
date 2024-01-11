#include <window/window_manager.h>

namespace gvsx {

	class cApp 
	{
	public:
		void Init();
		void Free();

		void Run();
		
	private:
		GLFWwindow* window;
	};

}
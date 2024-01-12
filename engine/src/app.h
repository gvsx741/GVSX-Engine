#pragma once
#include <render/context.h>
#include <window/window_manager.h>

//#include <render/render_system.h>

namespace gvsx {

	class cApp 
	{
	public:
		void Init();
		void Free();

		void Run();
	};

}
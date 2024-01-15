#pragma once
#include <render/render_system.h>
#include <window/window_manager.h>

namespace gvsx {

	class cApp 
	{
	public:
		void Init();
		void Free();

		void Run();
	};

}
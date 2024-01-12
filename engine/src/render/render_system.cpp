#include <render/render_system.h>

namespace gvsx {

	namespace render {

		using namespace context;
		
		cRenderSystem::cRenderSystem()
		{

		}

		cRenderSystem::~cRenderSystem()
		{

		}

		void cRenderSystem::Init(HWND hWnd)
		{
			InitDX11(hWnd);
		}

		void cRenderSystem::Free()
		{
			FreeDX11();
		}

		void cRenderSystem::Update()
		{

		}

	}
}
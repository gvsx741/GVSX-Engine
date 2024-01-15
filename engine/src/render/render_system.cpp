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

		void cRenderSystem::Init()
		{
			InitDX11();
		}

		void cRenderSystem::Free()
		{
			FreeDX11();
		}

		void cRenderSystem::Update()
		{
			Render();
		}

	}
}
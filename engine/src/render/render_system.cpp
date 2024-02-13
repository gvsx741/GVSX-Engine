#include <render/render_system.h>

#include <render/core/context.h>

#include <core/app.h>

namespace gvsx {

	namespace render {

		using namespace context;

		void cRenderSystem::Init()
		{
			InitDX11();

			LogInfo("Render system initialized");
		}

		void cRenderSystem::Reliase()
		{
			ReliaseDX11();

			LogInfo("Render system is released");
		}

		void cRenderSystem::Update()
		{
			Render();
		}
	}
}
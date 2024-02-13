#include <render/render_system.h>

#include <render/core/context.h>

#include <core/app.h>

namespace gvsx {

	namespace render {

		using namespace context;

		void cRenderSystem::Init()
		{
			LogInfo("Render system initialization");

			InitDX11();

			LogInfo("Render system initialized");
		}

		void cRenderSystem::Reliase()
		{
			ReliaseDX11();
			LogInfo("Render system free");
		}

		void cRenderSystem::Update()
		{
			Render();
		}
	}
}
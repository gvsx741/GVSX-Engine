#include <render/render_system.h>

#include <render/context.h>

#include <core/app.h>
#include <core/logger.h>

namespace gvsx {

	namespace render {

		using namespace core;
		using namespace context;

		void cRenderSystem::Init()
		{
			LogInfo("Render system initialization");

			InitDX11();

			LogInfo("Render system initialized");
		}

		void cRenderSystem::Free()
		{
			FreeDX11();
			LogInfo("Render system free");
		}

		void cRenderSystem::Update()
		{
			Render();
		}

	}
}
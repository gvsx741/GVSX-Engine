#include <render/render_system.h>

#include <render/core/context.h>

#include <core/app.h>

namespace gvsx {

	namespace render {

		using namespace context;

		cRenderSystem::cRenderSystem()
		{
			InitDX11();

			LogInfo("Render system initialized");
		}

		cRenderSystem::~cRenderSystem()
		{
			ReleaseDX11();

			LogInfo("Render system released");
		}

		void cRenderSystem::Init()
		{

		}

		void cRenderSystem::Release()
		{

		}

		void cRenderSystem::Update()
		{
			Render();
		}
	}
}
#pragma once

namespace gvsx {

	namespace render 
	{
		class cRenderSystem;
	}

	namespace core {

		using namespace render;

		class ENGINE_API cApp
		{
		public:
			void Run();

		protected:
			void Init();
			void Free();

			cRenderSystem* m_RenderSystem = nullptr;
		};
	}
}
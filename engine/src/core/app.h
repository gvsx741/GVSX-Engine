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
			void Reliase();

			cRenderSystem* m_RenderSystem = nullptr;
		};
	}
}
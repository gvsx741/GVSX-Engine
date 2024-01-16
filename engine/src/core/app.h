#pragma once

namespace gvsx {

	namespace render 
	{
		class cRenderSystem;
	}

	namespace core {

		using namespace render;

		class cApp 
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
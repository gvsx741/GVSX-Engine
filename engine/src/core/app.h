#pragma once

namespace gvsx {

	namespace render 
	{
		class cRenderSystem;
	}

	namespace core {

		using namespace render;

		class ENGINE_API cApp : public cObject
		{
		public:
			cApp();
			~cApp();

			void Run();

		private:
			cRenderSystem* m_RenderSystem = nullptr;
		};
	}
}
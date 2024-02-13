#pragma once

namespace gvsx {

	namespace render {

		class ENGINE_API cRenderSystem : public cSystem
		{
		public:
			void Init();
			void Release();
			
			void Update();
		};

	}
}
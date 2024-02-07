#pragma once

namespace gvsx {

	namespace render {

		class ENGINE_API cRenderSystem
		{
		public:
			void Init();
			void Reliase();
			
			void Update();

		private:
			void InitPipeline();
		};

	}
}
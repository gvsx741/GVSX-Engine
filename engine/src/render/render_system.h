#pragma once
#include <render/context.h>

namespace gvsx {

	namespace render {

		class cRenderSystem
		{
		public:
			cRenderSystem();
			~cRenderSystem();

			void Init();
			void Free();

			void Update();

		private:

		};

	}
}
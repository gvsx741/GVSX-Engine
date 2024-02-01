#pragma once

namespace gvsx {

	namespace core {

		class cSystem
		{
		protected:
			virtual void Init();
			virtual void Free();
			virtual void Update();
		};
	}
}
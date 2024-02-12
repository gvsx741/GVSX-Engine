#pragma once

namespace gvsx {

	namespace core {

		class ENGINE_API cSystem
		{
		public:
			virtual void Init() {};
			virtual void Reliase() {};
			virtual void Update() {};
		};
	}
}
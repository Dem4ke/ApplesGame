#pragma once
#include <vector>

namespace ApplesGame {

	// Settings 
	struct Settings {
		enum class GameOpptions {
			isApplesUnLimited = 1 << 0,
			isPlayerAccelerated = 1 << 1,

			Default = isApplesUnLimited | isPlayerAccelerated,
			Empty = 0
		};

	};
}

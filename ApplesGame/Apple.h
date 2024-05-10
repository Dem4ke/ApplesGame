#pragma once
#include "Player.h"

namespace ApplesGame {

	class Apple {
	public:
		Apple(Resources& resources) : resources_(resources) {}

//		void init(float size, int num);
	private:

		Resources& resources_;
	};
}
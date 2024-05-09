#pragma once

namespace ApplesGame {

	struct Vector2D {
		Vector2D(float x, float y) : x_(x), y_(y) {}

	private:
		float x_ = 0.f;
		float y_ = 0.f;
	};

	typedef Vector2D Position2D;

	Position2D GetRandomPositionInScreen(float screenWidth, float screenHeight);

	bool IsRectanglesCollide(Position2D rect1Position, Vector2D rect1Size,
		Position2D rect2Position, Vector2D rect2Size);

	bool IsCircusCollide(Position2D circle1Position, float circle1Radius,
		Position2D circle2Position, float circle2Radius);

}
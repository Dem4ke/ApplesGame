#include <SFML/Graphics.hpp>
#include "Math.h"
#include <cstdlib>

namespace ApplesGame {

	// Function to get random position
	Position2D GetRandomPositionInScreen(float screenWidth, float screenHeight) {	// class function
		Position2D result;															// class object
		result.x = rand() / (float)RAND_MAX * screenWidth;
		result.y = rand() / (float)RAND_MAX * screenHeight;
		return result;
	}

	bool IsRectanglesCollide(Position2D rect1Position, Vector2D rect1Size, Position2D rect2Position, Vector2D rect2Size) {
		const float dx = fabs(rect1Position.x - rect2Position.x);
		const float dy = fabs(rect1Position.y - rect2Position.y);
		return (dx <= (rect1Size.x + rect2Size.x) / 2.f &&
			dy <= (rect1Size.y + rect2Size.y) / 2.f);
	}

	bool IsCircusCollide(Position2D circle1Position, float circle1Radius, Position2D circle2Position, float circle2Radius) {
		const float squareDistance = (circle1Position.x - circle2Position.x) * (circle1Position.x - circle2Position.x) +
			(circle1Position.y - circle2Position.y) * (circle1Position.y - circle2Position.y);
		const float squareRadiusSum = (circle1Radius + circle2Radius) * (circle1Radius + circle2Radius) / 4;
		return squareDistance <= squareRadiusSum;
	}

	void SetSpriteSize(sf::Sprite& sprite, float desiredWidht, float desiredHeight) {
		sf::FloatRect spriteRect = sprite.getLocalBounds(); // get sprite size from corner
		sf::Vector2f scale = { desiredWidht / spriteRect.width, desiredHeight / spriteRect.height };
		sprite.setScale(scale);
	}

	void SetSpriteRelativeOrigin(sf::Sprite& sprite, float originX, float originY) {
		sf::FloatRect spriteRect = sprite.getLocalBounds();
		sprite.setOrigin(sf::Vector2f(originX * spriteRect.width, originY * spriteRect.height));
	}
}
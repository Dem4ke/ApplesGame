#pragma once
#include "Resources.h"
#include "Engine.h"

namespace ApplesGame {

	enum class PlayerDirection : int {
		Right = 0,
		Up,
		Left,
		Down
	};

	class Player {
	public:
		Player(Resources& resources) : resources_(resources), position_(0.f, 0.f) {}
		void init(float playerSize, float playerSpeed);
		float getSize() const;
		float getSpeed() const;
		Position2D getPosX() const;
		Position2D getPosY() const;

	private:
		float playerSize_ = 0.f;
		float playerSpeed_ = 0.f;
		sf::Sprite playerSprite_;
		Position2D position_;
		PlayerDirection direction_ = PlayerDirection::Right;

		Resources& resources_;
	};

	void DrawPlayer(Player& player, sf::RenderWindow& window);
}
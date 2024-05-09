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
		Player(Resources& resources) : resources_(resources), 
			position_(resources_.getWindowWidth() / 2.f, resources_.getWindowHeight() / 2.f) {}
		void init(float playerSize, float playerSpeed);
		float getSize() const;
		float getSpeed() const;
		float getPosX() const;
		float getPosY() const;
		sf::Sprite getSprite();

		float playerSize_ = 0.f;
		float playerSpeed_ = 0.f;
		Position2D position_;
		PlayerDirection direction_ = PlayerDirection::Right;

	private:
		sf::Sprite playerSprite_;
		Resources& resources_;
	};

	void PlayerMove(Player& player, const float& deltaTime);
	void OutOfWindow(Player& player);
	void DrawPlayer(Player& player, sf::RenderWindow& window);
}
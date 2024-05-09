#include "Player.h"

namespace ApplesGame {

	// PLAYER INITIALIZATION

	void Player::init(float playerSize, float playerSpeed) {
		position_ = { resources_.getWindowWidth() / 2.f, resources_.getWindowHeight() / 2.f };
		playerSize_ = playerSize;
		playerSpeed_ = playerSpeed;
		playerSprite_.setRotation(0.f);

		// Init player sprite
		playerSprite_.setTexture(resources_.playerTexture);
		SetSpriteSize(playerSprite_, playerSize_, playerSize_);
		SetSpriteRelativeOrigin(playerSprite_, 0.5f, 0.5f);
	}

	float Player::getSize() const { return playerSize_; }

	float Player::getSpeed() const { return playerSize_; }

	Position2D Player::getPosX() const { return position_.x_; }

	Position2D Player::getPosX() const { return position_.y_; }

	// FUNCTIONS

	void DrawPlayer(Player& player, sf::RenderWindow& window) {
		player.sprite.setPosition(player.position.x, player.position.y);
		window.draw(player.sprite);
		// Orient player sprite according to player direction
		if (player.direction == PlayerDirection::Left) {
			SetSpriteSize(player.sprite, -PLAYER_SIZE, PLAYER_SIZE);
			player.sprite.setRotation(0.f);
		}
		else {
			SetSpriteSize(player.sprite, PLAYER_SIZE, PLAYER_SIZE);
			player.sprite.setRotation((float)player.direction * -90.f);
		}
	}
}
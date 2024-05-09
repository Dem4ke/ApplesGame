#include "Player.h"

namespace ApplesGame {

	// PLAYER INITIALIZATION

	void Player::init(float playerSize, float playerSpeed) {
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

	float Player::getPosX() const { return position_.x; }

	float Player::getPosY() const { return position_.y; }

	sf::Sprite Player::getSprite() { return playerSprite_; }

	// FUNCTIONS
	
	// Player movement
	void PlayerMove(Player& player, const float& deltaTime) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			game.player.direction = PlayerDirection::Right;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			game.player.direction = PlayerDirection::Up;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			game.player.direction = PlayerDirection::Left;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			game.player.direction = PlayerDirection::Down;
		}

		switch (game.player.direction) {
		case PlayerDirection::Right: {
			game.player.position.x += game.player.speed * deltaTime;
			break;
		}
		case PlayerDirection::Up: {
			game.player.position.y -= game.player.speed * deltaTime;
			break;
		}
		case PlayerDirection::Left: {
			game.player.position.x -= game.player.speed * deltaTime;
			break;
		}
		case PlayerDirection::Down: {
			game.player.position.y += game.player.speed * deltaTime;
			break;
		}
		}
	}
	
	// Window border collision
	void OutOfWindow(Player& player) {
		if (game.player.position.x + PLAYER_SIZE / 2.f > SCREEN_WIDTH || game.player.position.x - PLAYER_SIZE / 2.f < 0.f ||
			game.player.position.y + PLAYER_SIZE / 2.f > SCREEN_HEIGHT || game.player.position.y - PLAYER_SIZE / 2.f < 0.f) {
			GameOverSound(game.resources, game);
			game.gameState |= Game::GameState::isGameOver;
			game.gameOverTime = 0;
		}
	}

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
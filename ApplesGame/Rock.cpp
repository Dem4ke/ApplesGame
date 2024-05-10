#include "Rock.h"

namespace ApplesGame {

	// ROCK INITIALIZATION

	void Rock::init(float size) {
		size_ = size;
		position_ = GetRandomPositionInScreen(resources_.getWindowWidth(), resources_.getWindowHeight());

		sprite_.setTexture(resources_.rockTexture);
		sprite_.setPosition(position_.x, position_.y);

		SetSpriteSize(sprite_, size_, size_);
		SetSpriteRelativeOrigin(sprite_, 0.5f, 0.5f);
	}

	float Rock::getSize() const { return size_; }

	sf::Sprite Rock::getSprite() const { return sprite_; }

	// FUNCTIONS

	void RockInit(Rock& rock, std::vector<Rock>& fieldOfRocks, float size, int num) {
		for (int i = 0; i < num; ++i) {
			rock.init(size);
			fieldOfRocks.push_back(rock);
		}
	}

	void RockCollision(std::vector<Rock>& rocks, Player& player, Resources& resources, Settings& settings) {
		int end = rock.getNumsOfRocks();

		for (int i = 0; i < end; ++i) {
			if (IsRectanglesCollide(player.position_, { player.getSize(), player.getSize() },
				rock.getPosition(i), {rock.getSize(), rock.getSize()})) {

				GameOverSound(resources);
				PushGameState(settings, GameStateType::GameOver);
			}
		}
	}

	void DrawRocks(std::vector<Rock>& rocks, sf::RenderWindow& window) {
		for (auto& i : rock.rocks_) {
			window.draw(i.sprite_);
		}
	}
}
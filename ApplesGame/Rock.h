#pragma once
#include "Player.h"

namespace ApplesGame {

	class Rock {
	public:
		Rock(Resources& resources) : resources_(resources) {}

		void init(float size);

		float getSize() const;
		sf::Sprite getSprite() const;
		
		Position2D position_;

	private:
		float size_ = 0.f;
		sf::Sprite sprite_;
		Resources& resources_;
	};

	void RockInit(Rock& rock, std::vector<Rock>& fieldOfRocks, float size, int num);
	void RockCollision(Rock& rock, Player& player, Resources& resources, Settings& settings);
	void DrawRocks(Rock& rock, sf::RenderWindow& window);
}
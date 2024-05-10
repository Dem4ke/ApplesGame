#pragma once
#include "Menu.h"
#include "Player.h"
#include "Apple.h"
#include "Rock.h"

namespace ApplesGame {

	class Game {
	public:
		Game(Resources& resources, sf::RenderWindow& window);

		void initGame();
		void restartGame();
		void updateMenu(sf::Event& event);
		void updateGame(const float& deltaTime);
		void gameOver(const float& deltaTime);
		void drawGame();
		
	private:
		sf::RenderWindow& window_;
		Resources& resources_;

		Menu mainMenu_;
		Menu optionsMenu_;
		Menu exitMenu_;
		Menu pauseMenu_;
		Menu gameOverMenu_;

		Player player_;
		Apple apple_;
		Rock rock_;
		
		std::vector<Apple> fieldOfApples_;
		std::vector<Rock> fieldOfRocks_;
		
		Settings settings_;
	};
}

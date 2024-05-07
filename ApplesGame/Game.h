#pragma once
#include "Menu.h"
#include "Resources.h"
#include "Settings.h"

namespace ApplesGame {

	class Game {
	public:
		Game(Resources& resources, sf::RenderWindow& window);

		void initGame();
		void restartGame();
		void updateGame( const float& deltaTime, sf::Event& event);
		void gameOver(const float& deltaTime);
		void drawGame();
		
	private:
		sf::RenderWindow& window_;
		Resources& resources_;
		Menu mainMenu_;
		Menu optionsMenu_;
		Menu exitMenu_;
		Settings settings_;
	};
}

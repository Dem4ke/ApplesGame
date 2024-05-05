#include "Game.h"

namespace ApplesGame {

	Game::Game(Resources& resources, MainMenu& mainMenu, sf::RenderWindow& window ) : resources_(resources), mainMenu_(mainMenu),
		window_(window) {}

	void Game::initGame() {
		std::vector<std::string> mainButtons = { "Play game", "Leader board", "Options", "Exit" };
		mainMenu_.init("Apples Game", mainButtons, 30);
	}
	
	void Game::restartGame() {

	}

	void Game::updateGame(const float& deltaTime, sf::Event& event) {
		MenuMovement(mainMenu_, event);
	}

	void Game::gameOver( const float& deltaTime) {

	}
	
	void Game::drawGame() {
		DrawMenu(mainMenu_, window_);
	}
}
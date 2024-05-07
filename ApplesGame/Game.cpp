#include "Game.h"

namespace ApplesGame {

	Game::Game(Resources& resources, sf::RenderWindow& window )
		: resources_(resources), window_(window), mainMenu_(resources), 
		optionsMenu_ (resources), exitMenu_(resources) {}

	void Game::initGame() {
		std::vector<std::string> mainButtons = { "Play game", "Leader board", "Options", "Exit" };
		std::vector<std::string> optionsButtons = { "Acceleration: On", "Infinite apples: On" };
		std::vector<std::string> exitButtons = { "Yes", "No"};
		mainMenu_.init("Apples Game", mainButtons, 30.f);
		optionsMenu_.init("Options", optionsButtons, 30.f);
		exitMenu_.init("Do you want to exit?", exitButtons, 30.f);

		PushGameState(settings_, GameStateType::MainMenu);
	}
	
	void Game::restartGame() {

	}

	void Game::updateGame(const float& deltaTime, sf::Event& event) {
		if (settings_.gameStateType == GameStateType::MainMenu) {
			MainMenuMovement(mainMenu_, settings_, event);
		} 
		else if (settings_.gameStateType == GameStateType::Options) {
			OptionsMenuMovement(optionsMenu_, settings_, event);
		}
		else if (settings_.gameStateType == GameStateType::ExitDialog) {
			ExitMenuMovement(exitMenu_, settings_, event, window_);
		}
	}

	void Game::gameOver( const float& deltaTime) {

	}
	
	void Game::drawGame() {
		if (settings_.gameStateType == GameStateType::MainMenu) {
			DrawMenu(mainMenu_, window_);
		}
		else if (settings_.gameStateType == GameStateType::ExitDialog) {
			DrawMenu(exitMenu_, window_);
		}
		else if (settings_.gameStateType == GameStateType::Options) {
			DrawMenu(optionsMenu_, window_);
		}
	}
}
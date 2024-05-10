#include "Game.h"

namespace ApplesGame {

	Game::Game(Resources& resources, sf::RenderWindow& window )
		: resources_(resources), window_(window), mainMenu_(resources), 
		optionsMenu_ (resources), exitMenu_(resources), pauseMenu_(resources),
		gameOverMenu_(resources), player_(resources), apple_(resources), rock_(resources) {}

	void Game::initGame() {
		std::vector<std::string> mainButtons = { "Play game", "Leader board", "Options", "Exit" };
		std::vector<std::string> optionsButtons = { "Acceleration: On", "Infinite apples: On" };
		std::vector<std::string> exitButtons = { "Yes", "No"};
		std::vector<std::string> pauseButtons = { "Yes", "No" };
		std::vector<std::string> gameOverButtons = { "Yes", "No" };

		// Menu initialization (Name of menu, buttons, size of buttons, Name of menu will be in 1.5 bigger
		mainMenu_.init("Apples Game", mainButtons, 40.f);
		optionsMenu_.init("Options", optionsButtons, 40.f);
		exitMenu_.init("Do you want to exit?", exitButtons, 40.f);
		pauseMenu_.init("Do you want to exit\n\tin main menu?\n", pauseButtons, 40.f);
		gameOverMenu_.init("\tGame Over\ndo you want to exit\n\tin main menu?\n\n", gameOverButtons, 40.f);

		// Player initialization (size of player, speed)
		player_.init(30.f, 100.f);
		// Apple initialization (size of apple, numbers of apples on field)
//		apple_.init(30.f, 20);
		// Rock initialization (size of rock, number of rocks on field)
		rock_.init(30.f, 5);

		PushGameState(settings_, GameStateType::MainMenu);
	}
	
	void Game::restartGame() {
		RestartGameState(settings_);
	}

	// Update menu states, it works only with Event
	void Game::updateMenu(sf::Event& event) {
		if (settings_.gameStateType == GameStateType::MainMenu) {
			MainMenuMovement(mainMenu_, settings_, event);
		} 
		else if (settings_.gameStateType == GameStateType::Options) {
			OptionsMenuMovement(optionsMenu_, settings_, event);
		}
		else if (settings_.gameStateType == GameStateType::ExitDialog) {
			ExitMenuMovement(exitMenu_, settings_, event, window_);
		}
		else if (settings_.gameStateType == GameStateType::Pause) {
			PauseMenuMovement(pauseMenu_, settings_, event);
		}
	}

	// Update only game process 
	void Game::updateGame(const float& deltaTime) {
		if (settings_.gameStateType == GameStateType::Game) {
			
			// Player movement
			PlayerMove(player_, deltaTime);

			// Window collision
			OutOfWindow(player_, resources_, settings_);

			// Collision with rocks
			RockCollision(rock_, player_, resources_, settings_);

			// Pause menu maker
			ExitInPauseMenu(settings_);
		}
	}

	void Game::gameOver(const float& deltaTime) {

	}
	
	void Game::drawGame() {
		if (settings_.gameStateType == GameStateType::MainMenu) {
			DrawMenu(mainMenu_, window_);
		}
		else if (settings_.gameStateType == GameStateType::Options) {
			DrawMenu(optionsMenu_, window_);
		}
		else if (settings_.gameStateType == GameStateType::ExitDialog) {
			DrawMenu(exitMenu_, window_);
		}
		else if (settings_.gameStateType == GameStateType::Pause) {
			DrawMenu(pauseMenu_, window_);
		}
		else if (settings_.gameStateType == GameStateType::GameOver) {
			DrawMenu(gameOverMenu_, window_);
		}
		else if (settings_.gameStateType == GameStateType::Game) {
			DrawPlayer(player_, window_);
			DrawRocks(rock_, window_);
		}
	}
}
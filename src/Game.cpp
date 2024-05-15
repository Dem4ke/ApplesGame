#include "Game.h"

namespace ApplesGame {

	Game::Game(Resources& resources, sf::RenderWindow& window )
		: resources_(resources), window_(window), mainMenu_(resources), 
		optionsMenu_ (resources), exitMenu_(resources), pauseMenu_(resources),
		gameOverMenu_(resources), player_(resources), apple_(resources),
		rock_(resources), leaderBoard_(resources), UI_(resources) {}

	void Game::initGame() {
		std::vector<std::string> mainButtons = { "Play game", "Leader board", "Options", "Exit" };
		std::vector<std::string> optionsButtons = { "Acceleration: On", "Infinite apples: On" };
		std::vector<std::string> exitButtons = { "Yes", "No"};
		std::vector<std::string> pauseButtons = { "Yes", "No" };
		std::vector<std::string> gameOverButtons = { "\n\n\n\n\n\n\n\n\n\nExit" };

		// Menu initialization (Name of menu, buttons, size of buttons, Name of menu will be in 1.5 bigger)
		mainMenu_.init("Apples Game", mainButtons, 40.f);
		optionsMenu_.init("Options", optionsButtons, 40.f);
		exitMenu_.init("Do you want to exit?", exitButtons, 40.f);
		pauseMenu_.init("Do you want to exit\n\tin main menu?\n", pauseButtons, 40.f);
		gameOverMenu_.init("Game Over\n\n", gameOverButtons, 40.f);

		// Leader board initialization (Name of menu, size of names, Settings class object)
		leaderBoard_.init("Leader Board", 40.f, settings_);

		// User interface initialization (size of button)
		UI_.init(20.f);

		restartGame();
	}
	
	void Game::restartGame() {
		// Reset game state 
		RestartGameState(settings_);

		// Player initialization (size of player, speed)
		player_.init(30.f, 100.f);

		// Apple initialization (size of apple, numbers of apples on field)
		ApplesFieldInit(apple_, fieldOfApples_, 20.f, settings_.numOfApples);

		// Update apples counter
		settings_.eatenApples_ = 0;
		UI_.appleCountUpdate(settings_);

		// Rock initialization (Rock class object, array of objects, size of rock, number of rocks on field)
		RocksFieldInit(rock_, fieldOfRocks_, 30.f, settings_.numOfRocks);
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
		else if (settings_.gameStateType == GameStateType::LeaderBoard) {
			LeaderBoardMovement(leaderBoard_, settings_, event);
		}
		else if (settings_.gameStateType == GameStateType::GameOver) {
			GameOverMenuMovement(gameOverMenu_, settings_, event);
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
			RockCollision(fieldOfRocks_, player_, resources_, settings_);

			// Pause menu maker
			ExitInPauseMenu(settings_);

			// Differents versions of collision with apples
			if ((settings_.gameSettings & GameOptions::isApplesInfinite) &&
				!(settings_.gameSettings & GameOptions::isPlayerAccelerated)) {
				
				InfApplesWithNoAcc(fieldOfApples_, player_, resources_, settings_, UI_);
			}
			else if ((settings_.gameSettings & GameOptions::isApplesInfinite) && (settings_.gameSettings & GameOptions::isPlayerAccelerated)) {
				
				InfApplesWithAcc(fieldOfApples_, player_, resources_, settings_, UI_);
			}
			else if (!(settings_.gameSettings & GameOptions::isApplesInfinite) && !(settings_.gameSettings & GameOptions::isPlayerAccelerated)) {
				
				LimApplesWithNoAcc(fieldOfApples_, player_, resources_, settings_, UI_);
			}
			else if (!(settings_.gameSettings & GameOptions::isApplesInfinite) && (settings_.gameSettings & GameOptions::isPlayerAccelerated)) {
				
				LimApplesWithAcc(fieldOfApples_, player_, resources_, settings_, UI_);
			}
		}
	}

	void Game::gameOver(const float& deltaTime) {
		if (settings_.gameStateType == GameStateType::GameOver) {
			leaderBoard_.sortTable(settings_);
		}
		else if (settings_.gameStateType == GameStateType::GameReset) {
			restartGame();
		}
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
			DrawLeaderBoard(leaderBoard_, window_);
		}
		else if (settings_.gameStateType == GameStateType::LeaderBoard) {
			DrawLeaderBoard(leaderBoard_, window_);
		}
		else if (settings_.gameStateType == GameStateType::Game) {
			DrawPlayer(player_, window_);
			DrawRocks(fieldOfRocks_, window_);
			DrawApples(fieldOfApples_, window_);
			DrawUI(UI_, window_);
		}
	}
}
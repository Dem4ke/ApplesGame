#include "Settings.h"

namespace ApplesGame {
	
	void Settings::appleIncrease() {
		++eatenApples_;
	}

	// Add a new game state in "game states stack"
	void PushGameState(Settings& settings, GameStateType newType) {
		settings.gameStates.push_back(newType);
		settings.gameStateType = settings.gameStates[settings.gameStates.size() - 1];
	}

	// Delete current game state from "game states stack"
	void PopGameState(Settings& settings) {
		settings.gameStates.pop_back();
		settings.gameStateType = settings.gameStates[settings.gameStates.size() - 1];
	}

	// Clear "game states stack" and set main menu
	void RestartGameState(Settings& settings) {
		settings.gameStates.clear();
		PushGameState(settings, GameStateType::MainMenu);
	}
}
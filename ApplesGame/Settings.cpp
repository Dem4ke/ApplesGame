#include "Settings.h"

namespace ApplesGame {
	
	void PushGameState(Settings& settings, GameStateType newType) {
		settings.gameStates.push_back(newType);
		settings.gameStateType = settings.gameStates[settings.gameStates.size() - 1];
	}
	void PopGameState(Settings& settings) {
		settings.gameStates.pop_back();
		settings.gameStateType = settings.gameStates[settings.gameStates.size() - 1];
	}
}
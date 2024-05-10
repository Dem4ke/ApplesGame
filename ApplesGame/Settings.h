#pragma once
#include <vector>

namespace ApplesGame {

	enum GameOptions {
		isPlayerAccelerated = 1,
		isApplesInfinite = 1 << 1,
	};

	enum class GameStateType {
		None = 0,
		MainMenu,
		Game,
		Pause,
		GameOver,
		LeaderBoard,
		Options,
		ExitDialog,
	};

	// Settings 
	struct Settings {
		char gameSettings = 0;
		GameStateType gameStateType = GameStateType::None;
		std::vector<GameStateType> gameStates;
	};

	void PushGameState(Settings& settings, GameStateType newType);
	void PopGameState(Settings& settings);
	void RestartGameState(Settings& settings);
}

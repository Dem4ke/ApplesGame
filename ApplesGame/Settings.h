#pragma once
#include <vector>

namespace ApplesGame {

	enum GameOptions {
		isApplesInfinite = 1 << 0,
		isPlayerAccelerated = 1 << 1,
	};

	enum class GameStateType {
		None = 0,
		MainMenu,
		GameReset,
		Game,
		Pause,
		GameOver,
		LeaderBoard,
		Options,
		ExitDialog,
	};

	// Settings 
	struct Settings {
		char gameSettings = 3;
		GameStateType gameStateType = GameStateType::None;
		std::vector<GameStateType> gameStates;

		int eatenApples_ = 0;
		int numOfApples = 20;
		int numOfRocks = 5;
	};

	void PushGameState(Settings& settings, GameStateType newType);
	void PopGameState(Settings& settings);
	void RestartGameState(Settings& settings);
}

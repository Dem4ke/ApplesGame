#pragma once
#include <vector>

namespace ApplesGame {

	enum class GameOptions {
		isApplesUnLimited = 1 << 0,
		isPlayerAccelerated = 1 << 1,

		Default = isApplesUnLimited | isPlayerAccelerated,
		Empty = 0
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
		GameStateType gameStateType = GameStateType::None;
		std::vector<GameStateType> gameStates;
	};

	void PushGameState(Settings& settings, GameStateType newType);
	void PopGameState(Settings& settings);
}

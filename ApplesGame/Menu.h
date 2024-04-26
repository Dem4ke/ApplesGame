#pragma once
#include "Settings.h"
#include "Resources.h"

namespace ApplesGame {

	enum class GameStateType {
		None = 0,
		MainMenu,
		Game,
		Pause,
		GameOver,
		LeaderBoard,
	};

	class Menu {
	public:
		Menu(Resources& resources) : resources_(resources) {}

	protected:
		Resources& resources_;
	};

	class MainMenu {
	public:
		MainMenu(Resources& resources) : resources_(resources) {}

		void Init(std::vector<std::string>& allButtons, int buttonSize);
		void Draw(sf::RenderWindow& window);
	private:
		Resources resources_;
		sf::RenderWindow window_;
		std::vector<sf::Text> buttons_;
	};

	class PauseMenu : public Menu {
	public:
		PauseMenu(Resources& resources) : Menu(resources) {}
	private:
		std::vector<sf::Text> buttons_;
	};

	class GameOverMenu : public Menu {
	public:
		GameOverMenu(Resources& resources) : Menu(resources) {}
	private:
		std::vector<sf::Text> buttons_;
	};
}
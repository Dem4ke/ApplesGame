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

	class MainMenu {
	public:
		MainMenu(Resources& resources) : resources_(resources) {}

		void init(std::string gameName, std::vector<std::string>& allButtons, int buttonSize);
		void moveUp();
		void moveDown();

		size_t getButtonsCount() const;
		sf::Text getButton(int num) const;
		sf::Text getGameName() const;
		sf::RectangleShape getBackground() const;
	private:
		char gameState_ = 0;
		int selectedButton_ = 0;

		std::vector<sf::Text> buttons_;
		sf::Text gameName_;
		sf::RectangleShape background;
		
		Resources& resources_;
	};

	void MenuMovement(MainMenu& menu, const sf::Event& event);
	void DrawMenu(MainMenu& menu, sf::RenderWindow& window);
}
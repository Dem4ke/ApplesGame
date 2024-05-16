#pragma once
#include <unordered_map>
#include <algorithm>
#include "Settings.h"
#include "Resources.h"

namespace ApplesGame {

	class Menu {
	public:
		Menu(Resources& resources) : resources_(resources) {}

		void init(std::string menuName, std::vector<std::string>& allButtons, float buttonSize);
		void moveUp();
		void moveDown();

		size_t getButtonsCount() const;
		int getSelectedButton() const;
		sf::Text getButton(int num) const;
		sf::Text getGeneralName() const;
		sf::RectangleShape getBackground() const;

		void changeButton(int num, std::string change);

	private:
		int selectedButton_ = 0;

		std::vector<sf::Text> buttons_;
		sf::Text menuName_;
		sf::RectangleShape background_;
		
		Resources& resources_;
	};

	class LeaderBoard {
	public:
		LeaderBoard(Resources& resources) : resources_(resources) {}

		void init(std::string menuName, float buttonSize, Settings& settings);
		void sortTable(Settings& settings);

		size_t getPositionsCount() const;
		sf::Text getName(int num) const;
		sf::Text getScore(int num) const;
		sf::Text getGeneralName() const;

	private:
		float posX_ = 0;
		float posY_ = 0;
		float buttonSize_ = 0;

		sf::Text playerName_;
		sf::Text playerScore_;
		sf::Text menuName_;

		std::vector<std::pair<std::string, int>> tableText_;
		std::vector<std::pair<sf::Text, sf::Text>> liderBoard_;
		std::unordered_map<std::string, int> table_;

		Resources& resources_;
	};

	void MainMenuMovement(Menu& mainMenu, Settings& settings, const sf::Event& event);
	void OptionsMenuMovement(Menu& optionsMenu, Settings& settings, const sf::Event& event);
	void ExitMenuMovement(Menu& exitMenu, Settings& settings, const sf::Event& event, sf::RenderWindow& window);
	void PauseMenuMovement(Menu& pauseMenu, Settings& settings, const sf::Event& event);
	void GameOverMenuMovement(Menu& gameOverMenu, Settings& settings, const sf::Event& event);
	void LeaderBoardMovement(LeaderBoard& leaderBoard, Settings& settings, const sf::Event& event);
	void ExitInPauseMenu(Settings& settings);
	void DrawMenu(Menu& mainMenu, sf::RenderWindow& window);
	void DrawLeaderBoard(LeaderBoard& leaderBoard, sf::RenderWindow& window);
}
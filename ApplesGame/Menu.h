#pragma once
#include "Settings.h"
#include "Resources.h"

namespace ApplesGame {

	class MainMenu {
	public:
		MainMenu(Resources& resources) : resources_(resources) {}

		void init(std::string generalName, std::vector<std::string>& allButtons, int buttonSize);
		void moveUp();
		void moveDown();

		size_t getButtonsCount() const;
		int getSelectedButton() const;
		sf::Text getButton(int num) const;
		sf::Text getGeneralName() const;
		sf::RectangleShape getBackground() const;

	private:
		int selectedButton_ = 0;

		std::vector<sf::Text> buttons_;
		sf::Text generalName_;
		sf::RectangleShape background;
		
		Resources& resources_;
	};

	class ExitMenu {
	public:
		ExitMenu(Resources& resources) : resources_(resources) {}

		void init(std::string generalName, std::vector<std::string>& allButtons, int buttonSize);
		void moveUp();
		void moveDown();

		size_t getButtonsCount() const;
		int getSelectedButton() const;
		sf::Text getButton(int num) const;
		sf::Text getGeneralName() const;
		sf::RectangleShape getBackground() const;

	private:
		int selectedButton_ = 0;

		std::vector<sf::Text> buttons_; 
		sf::Text generalName_;
		sf::RectangleShape background;

		Resources& resources_;
	};

	void MainMenuMovement(MainMenu& mainMenu, Settings& settings, const sf::Event& event);
	void ExitMenuMovement(ExitMenu& exitMenu, Settings& settings, const sf::Event& event, sf::RenderWindow& window);
	void DrawMainMenu(MainMenu& mainMenu, sf::RenderWindow& window);
	void DrawExitMenu(ExitMenu& exitMenu, sf::RenderWindow& window);
}
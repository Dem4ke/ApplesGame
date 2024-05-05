#include "Menu.h"

namespace ApplesGame {
	// Initialization of all menu buttons
	// Example 
	void MainMenu::init(std::string gameName, std::vector<std::string>& allButtons, int buttonSize) {	
		float posX = resources_.getWindowWidth() / 2.f;
		float posY = resources_.getWindowHeight() / 2.f;

		// Initialization of background of main menu
		background.setSize(sf::Vector2f(resources_.getWindowWidth(), resources_.getWindowHeight()));
		background.setFillColor(sf::Color::Black);
		background.setPosition(0.f, 0.f);

		// Initialization of name of a game
		gameName_.setFont(resources_.font);
		gameName_.setCharacterSize(buttonSize * 2);
		gameName_.setFillColor(sf::Color::Red);
		gameName_.setString(gameName);
		gameName_.setOrigin(sf::Vector2f(gameName_.getGlobalBounds().width / 2.f, gameName_.getGlobalBounds().height / 2.f));
		gameName_.setPosition(posX, posY - (posY / 2.f));

		// Initialization of menu's buttons
		sf::Text menuButtons_;
		int space = buttonSize;
		menuButtons_.setFont(resources_.font);
		menuButtons_.setCharacterSize(buttonSize);
		menuButtons_.setFillColor(sf::Color::White);

		buttons_.clear();
		for (auto& i : allButtons) {
			menuButtons_.setString(i);
			menuButtons_.setOrigin(sf::Vector2f(menuButtons_.getGlobalBounds().width / 2.f, menuButtons_.getGlobalBounds().height / 2.f));
			menuButtons_.setPosition(posX, posY + space * 1.2f);
			buttons_.push_back(menuButtons_);
			space += buttonSize;
		}
	}

	void MainMenu::moveUp() {
		if (selectedButton_ >= 0) {
			buttons_[selectedButton_].setFillColor(sf::Color::White);
			--selectedButton_;

			if (selectedButton_ < 0) {
				selectedButton_ = buttons_.size() - 1;
			}
			buttons_[selectedButton_].setFillColor(sf::Color::Yellow);
		} 
	}

	void MainMenu::moveDown() {
		int end = buttons_.size();

		if (selectedButton_ <= end) {
			buttons_[selectedButton_].setFillColor(sf::Color::White);
			++selectedButton_;

			if (selectedButton_ == end) {
				selectedButton_ = 0;
			}
			buttons_[selectedButton_].setFillColor(sf::Color::Yellow);
		}
	}

	size_t MainMenu::getButtonsCount() const { return buttons_.size(); }

	sf::Text MainMenu::getButton(int num) const { return buttons_[num]; }

	sf::Text MainMenu::getGameName() const { return gameName_; }

	sf::RectangleShape MainMenu::getBackground() const { return background; }


	void MenuMovement(MainMenu& menu, const sf::Event& event) {
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Up) {
				menu.moveUp();
			}
			else if (event.key.code == sf::Keyboard::Down) {
				menu.moveDown();
			}
		}
	}

	void DrawMenu(MainMenu& menu, sf::RenderWindow& window) {
		window.draw(menu.getBackground());
		window.draw(menu.getGameName());
		for (size_t i = 0, it = menu.getButtonsCount(); i < it; ++i) {
			window.draw(menu.getButton(i));
		}
	}
}
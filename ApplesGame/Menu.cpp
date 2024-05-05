#include "Menu.h"

namespace ApplesGame {
	// MAIN MENU REALIZATION

	// Initialization of all menu buttons
	void MainMenu::init(std::string generalName, std::vector<std::string>& allButtons, int buttonSize) {
		float posX = resources_.getWindowWidth() / 2.f;
		float posY = resources_.getWindowHeight() / 3.f;

		// Initialization of background of main menu
		background.setSize(sf::Vector2f(resources_.getWindowWidth(), resources_.getWindowHeight()));
		background.setFillColor(sf::Color::Black);
		background.setPosition(0.f, 0.f);

		// Initialization of name of a game
		generalName_.setFont(resources_.font);
		generalName_.setCharacterSize(buttonSize * 2);
		generalName_.setFillColor(sf::Color::Red);
		generalName_.setString(generalName);
		generalName_.setOrigin(sf::Vector2f(generalName_.getGlobalBounds().width / 2.f, generalName_.getGlobalBounds().height / 2.f));
		generalName_.setPosition(posX, posY - buttonSize);

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
			buttons_[selectedButton_].setFillColor(sf::Color::Red);
		} 
	}

	void MainMenu::moveDown() {
		size_t end = buttons_.size();

		if (selectedButton_ <= end) {
			buttons_[selectedButton_].setFillColor(sf::Color::White);
			++selectedButton_;

			if (selectedButton_ == end) {
				selectedButton_ = 0;
			}
			buttons_[selectedButton_].setFillColor(sf::Color::Red);
		}
	}

	size_t MainMenu::getButtonsCount() const { return buttons_.size(); }

	int MainMenu::getSelectedButton() const { return selectedButton_; }

	sf::Text MainMenu::getButton(int num) const { return buttons_[num]; }

	sf::Text MainMenu::getGeneralName() const { return generalName_; }

	sf::RectangleShape MainMenu::getBackground() const { return background; }

	// EXIT MENU REALIZATION

	void ExitMenu::init(std::string generalName, std::vector<std::string>& allButtons, int buttonSize) {
		float posX = resources_.getWindowWidth() / 2.f;
		float posY = resources_.getWindowHeight() / 3.f;

		// Initialization of background of exit menu
		background.setSize(sf::Vector2f(resources_.getWindowWidth(), resources_.getWindowHeight()));
		background.setFillColor(sf::Color::Black);
		background.setPosition(0.f, 0.f);

		// Initialization of question of exist
		generalName_.setFont(resources_.font);
		generalName_.setCharacterSize(buttonSize);
		generalName_.setFillColor(sf::Color::White);
		generalName_.setString(generalName);
		generalName_.setOrigin(sf::Vector2f(generalName_.getGlobalBounds().width / 2.f, generalName_.getGlobalBounds().height / 2.f));
		generalName_.setPosition(posX, posY - buttonSize);

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

	void ExitMenu::moveUp() {
		if (selectedButton_ >= 0) {
			buttons_[selectedButton_].setFillColor(sf::Color::White);
			--selectedButton_;

			if (selectedButton_ < 0) {
				selectedButton_ = buttons_.size() - 1;
			}
			buttons_[selectedButton_].setFillColor(sf::Color::Red);
		}
	}

	void ExitMenu::moveDown() {
		size_t end = buttons_.size();

		if (selectedButton_ <= end) {
			buttons_[selectedButton_].setFillColor(sf::Color::White);
			++selectedButton_;

			if (selectedButton_ == end) {
				selectedButton_ = 0;
			}
			buttons_[selectedButton_].setFillColor(sf::Color::Red);
		}
	}

	size_t ExitMenu::getButtonsCount() const { return buttons_.size(); }

	int ExitMenu::getSelectedButton() const { return selectedButton_; }

	sf::Text ExitMenu::getButton(int num) const { return buttons_[num]; }

	sf::Text ExitMenu::getGeneralName() const { return generalName_; }

	sf::RectangleShape ExitMenu::getBackground() const { return background; }

	// FUNCTIONS

	void MainMenuMovement(MainMenu& mainMenu, Settings& settings, const sf::Event& event) {
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Up) {
				mainMenu.moveUp();
			}
			else if (event.key.code == sf::Keyboard::Down) {
				mainMenu.moveDown();
			}
			else if (event.key.code == sf::Keyboard::Escape) {
				PushGameState(settings, GameStateType::ExitDialog);
			}
			else if (event.key.code == sf::Keyboard::Enter) {
				if (mainMenu.getSelectedButton() == 0) {
					PushGameState(settings, GameStateType::Game);
				}
				else if (mainMenu.getSelectedButton() == 1) {
					PushGameState(settings, GameStateType::LeaderBoard);
				}
				else if (mainMenu.getSelectedButton() == 2) {
					PushGameState(settings, GameStateType::Options);
				}
				else if (mainMenu.getSelectedButton() == 3) {
					PushGameState(settings, GameStateType::ExitDialog);
				}
			}
		}
	}

	void ExitMenuMovement(ExitMenu& exitMenu, Settings& settings, const sf::Event& event, sf::RenderWindow& window) {
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Up) {
				exitMenu.moveUp();
			}
			else if (event.key.code == sf::Keyboard::Down) {
				exitMenu.moveDown();
			}
			else if (event.key.code == sf::Keyboard::Escape) {
				PopGameState(settings);
			}
			else if (event.key.code == sf::Keyboard::Enter) {
				if (exitMenu.getSelectedButton() == 0) {
					window.close();
					return;
				}
				else if (exitMenu.getSelectedButton() == 1) {
					PopGameState(settings);
				}
			}
		}
	}

	void DrawMainMenu(MainMenu& mainMenu, sf::RenderWindow& window) {
		window.draw(mainMenu.getBackground());
		window.draw(mainMenu.getGeneralName());
		for (size_t i = 0, it = mainMenu.getButtonsCount(); i < it; ++i) {
			window.draw(mainMenu.getButton(i));
		}
	}

	void DrawExitMenu(ExitMenu& exitMenu, sf::RenderWindow& window) {
		window.draw(exitMenu.getBackground());
		window.draw(exitMenu.getGeneralName());
		for (size_t i = 0, it = exitMenu.getButtonsCount(); i < it; ++i) {
			window.draw(exitMenu.getButton(i));
		}
	}
}
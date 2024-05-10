#include "Menu.h"

namespace ApplesGame {

	// Initialization of all menu buttons
	void Menu::init(std::string menuName, std::vector<std::string>& allButtons, float buttonSize) {
		float posX = resources_.getWindowWidth() / 2.f;
		float posY = resources_.getWindowHeight() / 3.f;

		// Initialization of background of menu
		background_.setSize(sf::Vector2f(resources_.getWindowWidth(), resources_.getWindowHeight()));
		background_.setFillColor(sf::Color::Black);
		background_.setPosition(0.f, 0.f);

		// Initialization of name of a game
		menuName_.setFont(resources_.font);
		menuName_.setCharacterSize(buttonSize * 1.5f);
		menuName_.setFillColor(sf::Color::Red);
		menuName_.setString(menuName);
		menuName_.setOrigin(sf::Vector2f(menuName_.getGlobalBounds().width / 2.f, menuName_.getGlobalBounds().height / 2.f));
		menuName_.setPosition(posX, posY - buttonSize);

		// Initialization of menu's buttons
		sf::Text menuButtons_;
		float space = buttonSize;
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

		// Color of the first button
		int selectedButton_ = 0;
		buttons_[selectedButton_].setFillColor(sf::Color::Red);
	}

	void Menu::moveUp() {
		if (selectedButton_ >= 0) {
			buttons_[selectedButton_].setFillColor(sf::Color::White);
			--selectedButton_;

			if (selectedButton_ < 0) {
				selectedButton_ = buttons_.size() - 1;
			}
			buttons_[selectedButton_].setFillColor(sf::Color::Red);
		} 
	}

	void Menu::moveDown() {
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

	size_t Menu::getButtonsCount() const { return buttons_.size(); }

	int Menu::getSelectedButton() const { return selectedButton_; }

	sf::Text Menu::getButton(int num) const { return buttons_[num]; }

	sf::Text Menu::getGeneralName() const { return menuName_; }

	sf::RectangleShape Menu::getBackground() const { return background_; }

	void Menu::changeButton(int num, std::string change) { buttons_[num].setString(change); }

	// FUNCTIONS

	void MainMenuMovement(Menu& mainMenu, Settings& settings, const sf::Event& event) {
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

	void OptionsMenuMovement(Menu& optionsMenu, Settings& settings, const sf::Event& event) {
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Up) {
				optionsMenu.moveUp();
			}
			else if (event.key.code == sf::Keyboard::Down) {
				optionsMenu.moveDown();
			}
			else if (event.key.code == sf::Keyboard::Escape) {
				PopGameState(settings);
			}
			else if (event.key.code == sf::Keyboard::Enter) {
				if (optionsMenu.getSelectedButton() == 0) {
					if (optionsMenu.getButton(0).getString() == "Acceleration: On") {
						optionsMenu.changeButton(0, "Acceleration: Off");
						settings.gameSettings &= ~(GameOptions::isPlayerAccelerated);
					}
					else if (optionsMenu.getButton(0).getString() == "Acceleration: Off") {
						optionsMenu.changeButton(0, "Acceleration: On");
						settings.gameSettings |= GameOptions::isPlayerAccelerated;
					}
				}
				else if (optionsMenu.getSelectedButton() == 1) {
					if (optionsMenu.getButton(1).getString() == "Infinite apples: On") {
						optionsMenu.changeButton(1, "Infinite apples: Off");
						settings.gameSettings &= ~(GameOptions::isApplesInfinite);
					}
					else if (optionsMenu.getButton(1).getString() == "Infinite apples: Off") {
						optionsMenu.changeButton(1, "Infinite apples: On");
						settings.gameSettings |= GameOptions::isApplesInfinite;
					}
				}
			}
		}
	}

	void ExitMenuMovement(Menu& exitMenu, Settings& settings, const sf::Event& event, sf::RenderWindow& window) {
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

	void PauseMenuMovement(Menu& pauseMenu, Settings& settings, const sf::Event& event) {
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Up) {
				pauseMenu.moveUp();
			}
			else if (event.key.code == sf::Keyboard::Down) {
				pauseMenu.moveDown();
			}
			else if (event.key.code == sf::Keyboard::Escape) {
				PopGameState(settings);
			}
			else if (event.key.code == sf::Keyboard::Enter) {
				if (pauseMenu.getSelectedButton() == 0) {
					PushGameState(settings, GameStateType::GameReset);
				}
				else if (pauseMenu.getSelectedButton() == 1) {
					PopGameState(settings);
				}
			}
		}
	}

	void ExitInPauseMenu(Settings& settings) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			PushGameState(settings, GameStateType::Pause);
		}
	}

	void DrawMenu(Menu& menu, sf::RenderWindow& window) {
		window.draw(menu.getBackground());
		window.draw(menu.getGeneralName());
		for (int i = 0, it = menu.getButtonsCount(); i < it; ++i) {
			window.draw(menu.getButton(i));
		}
	}
}
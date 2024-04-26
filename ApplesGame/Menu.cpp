#include <array>
#include "Menu.h"

namespace ApplesGame {
	// Initialization of all menu buttons 
	// Example of input (mainButtons, 30)
	void MainMenu::Init(std::vector<std::string>& allButtons, int buttonSize) {
		int space = buttonSize;
		sf::Text button;
		button.setFont(resources_.getFont());
		button.setCharacterSize(buttonSize);
		button.setFillColor(sf::Color::Red);
		for (std::string i : allButtons) {
			button.setString(i);
			button.setPosition(resources_.getWindowHeight() / 1.5f - space, resources_.getWindowWidth() / 2.f);
			buttons_.push_back(button);
			space += buttonSize;
		}
	}
	// Draw menu
	void MainMenu::Draw(sf::RenderWindow& window) {
		window.draw(buttons_[1]);
	}
}
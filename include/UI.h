#pragma once
#include "Settings.h"
#include "Resources.h"

namespace ApplesGame {
	
	class UI {
	public:
		UI(Resources& resources) : resources_(resources) {}
		void init(float buttonSize);
		void appleCountUpdate(Settings& settings);

		sf::Text getHelp() const;
		sf::Text getScore() const;
	private:
		sf::Text controlHelp_;
		sf::Text score_;

		Resources& resources_;
	};

	void DrawUI(UI& UI, sf::RenderWindow& window);
}
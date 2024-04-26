#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

namespace ApplesGame {
	class Resources {
	public:
		Resources(float width, float height);
		
		void setTextures();
		void setSounds();
		void setFont(std::string font);

		float getWindowWidth() const;
		float getWindowHeight() const;
		sf::Font getFont() const;
		std::string getResourcesPath() const;
	private:
		sf::Texture player_;
		sf::Sound sound_;
		sf::Font font_;
		float width_ = 0;
		float height_ = 0;
		const std::string resourcesPath_ = "Resources/";
	};

}

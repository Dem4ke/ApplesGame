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
		void setFont();

		float getWindowWidth() const;
		float getWindowHeight() const;
		std::string getResourcesPath() const;

		sf::Texture playerTexture;
		sf::Sound deathSound;
		sf::Font font;
	
	private:
		float width_ = 0;
		float height_ = 0;
		const std::string resourcesPath_ = "Resources/";
	};

}

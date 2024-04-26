#include <cassert>
#include "Resources.h"

namespace ApplesGame {
	Resources::Resources(float width, float height) : width_(width), height_(height) {
		setTextures();
		setSounds();
		setFont("Roboto-Regular.ttf");
	}
	// Load texures from resources path
	void Resources::setTextures() {
		//assert();
	}
	// Load sounds from resources path
	void Resources::setSounds() {
	//	assert();
	 }
	// Load fonts from resources path
	void Resources::setFont(std::string font) {
		assert(font_.loadFromFile(resourcesPath_ + "Fonts/" + font));
	}

	// Get width of window
	float Resources::getWindowWidth() const {
		return width_;
	}
	// Get height of window
	float Resources::getWindowHeight() const {
		return height_;
	}
	// Get font
	sf::Font Resources::getFont() const {
		return font_;
	}
	std::string Resources::getResourcesPath() const {
		return resourcesPath_;
	}	
}
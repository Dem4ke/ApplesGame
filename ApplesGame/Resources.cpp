#include <cassert>
#include "Resources.h"

namespace ApplesGame {
	Resources::Resources(float width, float height) : width_(width), height_(height) {
		setTextures();
		setSounds();
		setFont();
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
	void Resources::setFont() {
		assert(font.loadFromFile(resourcesPath_ + "\\Fonts\\Roboto-Regular.ttf"));
	}

	
	float Resources::getWindowWidth() const { return width_; }
	
	float Resources::getWindowHeight() const { return height_; }
	
	std::string Resources::getResourcesPath() const { return resourcesPath_; }	
}
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Resources.h"
#include "Game.h"

int main() {

	int seed = (int)time(nullptr);
	srand(seed);

	// Game initialization
	ApplesGame::Resources resources{ 800.f, 600.f };
	sf::RenderWindow window(sf::VideoMode(resources.getWindowWidth(), resources.getWindowHeight()), "Apples Game!");

	ApplesGame::Game game{ resources, window };

	game.initGame();

	// Initialization of clocks
	sf::Clock gameClock;
	float lastTime = gameClock.getElapsedTime().asSeconds();

	// Main loop
	while (window.isOpen()) {

		// Reduse framerate to not spam CPU and GPU
		sf::sleep(sf::milliseconds(6));

		// Calculate time delta
		float currentTime = gameClock.getElapsedTime().asSeconds();
		float deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		// OS state checkout
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
				break;
			}

			// Update game state
			game.updateGame(deltaTime, event);
		}

	//	ApplesGame::GameOver(game, deltaTime);

		// Draw game
		window.clear();
		game.drawGame();
		window.display();
	}

	return 0;
}
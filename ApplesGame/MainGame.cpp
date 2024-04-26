#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Game.h"
#include "Menu.h"

int main() {

	int seed = (int)time(nullptr);
	srand(seed);

	// Initializaton window 
	ApplesGame::Resources resources{ 600.f, 400.f };
	sf::RenderWindow window(sf::VideoMode(resources.getWindowWidth(), resources.getWindowHeight()), "Apples Game!");
	ApplesGame::MainMenu mainMenu{ resources, window };
	std::vector<std::string> mainMenuButtons = { "Play game", "Leader Board", "Settings", "Exit" };
	mainMenu.Init(mainMenuButtons, 40);
	sf::RectangleShape background;
	background.setSize(sf::Vector2f(600.f, 400.f));
	background.setFillColor(sf::Color::Black);
	background.setPosition(0.f, 0.f);
	// Game initialization
	/*ApplesGame::Game game;
	ApplesGame::InitGame(game);
	*/
	// Initialization clocks
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

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
				break;
			}
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				window.close();
				break;
			}
		}

		// Update game state
		/*ApplesGame::UpdateGame(game, deltaTime);
		ApplesGame::GameOver(game, deltaTime);
		*/
		// Draw game
		window.clear();
		//ApplesGame::DrawGame(game, window);
		window.draw(background);
		window.display();
	}

	return 0;
}


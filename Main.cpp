#include "SFML/Graphics.hpp"
#include <string>
#include <iostream>

#include "GameWindow.h"
#include "Player.h"


int main()
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGTH = 600;
	const unsigned int FRAMERATE_LIMIT = 60;
	const std::string windowTitle = "Asteroids";
	const sf::Color backgroundColor = sf::Color::Black;

	GameWindow window(WINDOW_WIDTH, WINDOW_HEIGTH, FRAMERATE_LIMIT, windowTitle, backgroundColor);

	window.gameLoop();

	return 0;
}
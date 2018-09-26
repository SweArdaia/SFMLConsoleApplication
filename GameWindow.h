#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "SFML/Graphics.hpp"
#include <string>
#include <iostream>
#include "Player.h"
#include "TextureLoader.h"

class GameWindow
{
public:
	GameWindow(int width, int height, int framerateLimit, std::string windowName, sf::Color background);
	~GameWindow();

	//main game loop
	void gameLoop();

private:
	//Constants
	const float VELOCITY_INCREMENT = 1;
	const float VELOCITY_BLEED = 0.9;

	//objects
	Player player;
	TextureLoader textures;

	//window variables
	sf::VideoMode videoMode;
	sf::RenderWindow window;
	sf::Color backgroundColor;
	sf::Event event;

	//gameLoop functions
	void checkIfClose();
	void move();
	void bleedVelocity();
	void bleedY();
	void bleedX();

	//input functions
	void checkForInput();
	void processInput();
	bool isAnyKeyPressed();
	void clearKeys();

	//input checkers
	bool moveUp = false;
	bool moveDown = false;
	bool moveLeft = false;
	bool moveRight = false;

	//collision
	void checkCollision(); 

	//animations
	void animate();
};

#endif
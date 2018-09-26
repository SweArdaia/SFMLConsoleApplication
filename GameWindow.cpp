#include "GameWindow.h"


GameWindow::GameWindow(int WINDOW_WIDTH, int WINDOW_HEIGHT, int FRAMERATE_LIMIT, std::string WINDOW_NAME, sf::Color background) :
	backgroundColor(background), videoMode(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT))
{
	window.create(videoMode, WINDOW_NAME, sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(FRAMERATE_LIMIT);
	textures = TextureLoader();
	textures.setPlayerAnim();
	player.sprite.setPosition(window.getSize().x / 2, window.getSize().y / 2);
	player.setTexture(textures.ship);
	player.setFrame(textures.vAnim, 0, 0);
}


GameWindow::~GameWindow()
{
}

//gameloop functions
void GameWindow::gameLoop()
{
	while (window.isOpen())
	{
		checkIfClose();

		window.clear(backgroundColor);

		window.draw(player.sprite);

		checkForInput();
		processInput();
		checkCollision();
		
		move();

		bleedVelocity();
		if (!isAnyKeyPressed())
		{
			clearKeys();
		}


		window.display();
	}
}

void GameWindow::move()
{
	player.sprite.move(player.v.x, player.v.y);
}

void GameWindow::bleedVelocity()
{
	if (!moveLeft && !moveRight)
	{
		bleedX();
	}
	if (!moveUp && !moveDown)
	{
		bleedY();
	}
}

void GameWindow::bleedY()
{
	if (player.v.y != 0)
	{
		player.v.y *= VELOCITY_BLEED;
	}
}

void GameWindow::bleedX()
{
	if (player.v.x != 0)
	{
		player.v.x *= VELOCITY_BLEED;
	}
}

// input functions
void GameWindow::checkIfClose()
{
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}

void GameWindow::checkForInput()
{
	switch (event.type)
	{
	case sf::Event::KeyPressed:
		if (event.key.code == sf::Keyboard::Left) //check if A or left key is pressed
		{
			moveLeft = true;
		}
		if (event.key.code == sf::Keyboard::Right) // check if D or right key is pressed
		{
			moveRight = true;
		}
		if (event.key.code == sf::Keyboard::Up) // check if W or up key is pressed
		{
			moveUp = true;
		}
		if (event.key.code == sf::Keyboard::Down) // check if S or down key is pressed
		{
			moveDown = true;
		}
		break;
	case sf::Event::KeyReleased:
		if (event.key.code == sf::Keyboard::Left) //check if A or left key is pressed
		{
			moveLeft = false;
		}
		if (event.key.code == sf::Keyboard::Right) // check if D or right key is pressed
		{
			moveRight = false;
		}
		if (event.key.code == sf::Keyboard::Up) // check if W or up key is pressed
		{
			moveUp = false;
		}
		if (event.key.code == sf::Keyboard::Down) // check if S or down key is pressed
		{
			moveDown = false;
		}
		break;
	}
}

void GameWindow::clearKeys()
{
	moveUp = false;
	moveDown = false;
	moveLeft = false;
	moveRight = false;
}

bool GameWindow::isAnyKeyPressed()
{
	for (int i = -1; i < sf::Keyboard::KeyCount; i++)
	{
		if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(i)))
			return true;
	}
	return false;
}

void GameWindow::processInput()
{
	if (moveUp)
	{
		if (player.v.y > -player.maxY)
		{
			player.v.y -= VELOCITY_INCREMENT;
		}
	}
	if (moveDown)
	{
		if (player.v.y < player.maxY)
		{
			player.v.y += VELOCITY_INCREMENT;
		}
	}
	if (moveLeft)
	{
		if (player.v.x > -player.maxX)
		{
			player.v.x -= VELOCITY_INCREMENT;
		}
	}
	if (moveRight)
	{
		if (player.v.x < player.maxX)
		{
			player.v.x += VELOCITY_INCREMENT;
		}
	}
}

//collision
void GameWindow::checkCollision()
{
	if (player.sprite.getPosition().y <= 0) // check top collision
	{
		std::cout << "collisionY" << std::endl;
		player.sprite.setPosition(player.sprite.getPosition().x, 1);
		player.v.y -= player.v.y*2;
	}
	if (player.sprite.getPosition().x <= 0) //check left collision
	{
		std::cout << "collisionX" << std::endl;
		player.sprite.setPosition(1, player.sprite.getPosition().y);
		player.v.x -= player.v.x*2;
	}
	if (player.sprite.getPosition().y + player.sprite.getGlobalBounds().height >= window.getSize().y) // check bottom collision
	{
		std::cout << "collisionY" << std::endl;
		player.sprite.setPosition(player.sprite.getPosition().x, window.getSize().y - (player.sprite.getGlobalBounds().height + 1));
		player.v.y -= player.v.y * 2;
	}
	if (player.sprite.getPosition().x + player.sprite.getGlobalBounds().width >= window.getSize().x) // check right collision
	{
		std::cout << "collisionX" << std::endl;
		player.sprite.setPosition(window.getSize().x - (player.sprite.getGlobalBounds().width + 1), player.sprite.getPosition().y);
		player.v.x -= player.v.x * 2;
	}
}

//animations
void GameWindow::animate()
{

}


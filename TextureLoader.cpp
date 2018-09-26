#include "TextureLoader.h"


TextureLoader::TextureLoader()
{
	ship.loadFromFile("ship.png");
}


TextureLoader::~TextureLoader()
{
}


std::vector<Animation> TextureLoader::setPlayerAnim()
{
	Animation anim;

	//stationary
	anim.frames.push_back(sf::IntRect(1, 1, 50, 50));
	anim.frames.push_back(sf::IntRect(52, 1, 50, 50));
	anim.frames.push_back(sf::IntRect(103, 1, 50, 50));
	vAnim.push_back(anim);

	anim.frames.clear();

	//move up
	anim.frames.push_back(sf::IntRect(1, 154, 50, 50));
	anim.frames.push_back(sf::IntRect(52, 154, 50, 50));
	anim.frames.push_back(sf::IntRect(103, 154, 50, 50));
	vAnim.push_back(anim);

	anim.frames.clear();

	//move down
	anim.frames.push_back(sf::IntRect(1, 205, 50, 50));
	anim.frames.push_back(sf::IntRect(52, 205, 50, 50));
	anim.frames.push_back(sf::IntRect(103, 205, 50, 50));
	vAnim.push_back(anim);

	anim.frames.clear();

	//move left
	anim.frames.push_back(sf::IntRect(1, 103, 50, 50));
	anim.frames.push_back(sf::IntRect(52, 103, 50, 50));
	anim.frames.push_back(sf::IntRect(103, 103, 50, 50));
	vAnim.push_back(anim);

	anim.frames.clear();

	//move right
	anim.frames.push_back(sf::IntRect(1, 52, 50, 50));
	anim.frames.push_back(sf::IntRect(52, 52, 50, 50));
	anim.frames.push_back(sf::IntRect(103, 52, 50, 50));
	vAnim.push_back(anim);

	anim.frames.clear();

	return vAnim;
}
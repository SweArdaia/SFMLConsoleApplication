#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include "SFML/Graphics.hpp"
#include "Animation.h"
#include <vector>

class TextureLoader
{
public:
	TextureLoader();
	~TextureLoader();

	sf::Texture ship;

	std::vector<Animation> vAnim;

	std::vector<Animation> setPlayerAnim();
};

#endif
#ifndef SPRITEOBJ_H
#define SPRITEOBJ_H

#include "SFML/Graphics.hpp"
#include "Animation.h"
#include <vector>

class SpriteObj
{
public:
	SpriteObj();
	~SpriteObj();

	sf::Sprite sprite;
	sf::Vector2f v;

	float maxX = 0;
	float maxY = 0;

	void setFrame(std::vector<Animation> anim, int index, int frame);
	void setTexture(sf::Texture texture);

protected:
	sf::Texture texture;
};

#endif
#include "SpriteObj.h"

SpriteObj::SpriteObj()
{
	v.x = 0;
	v.y = 0;
}

SpriteObj::~SpriteObj()
{
}

void SpriteObj::setFrame(std::vector<Animation> anim, int index, int frame)
{
	sprite.setTextureRect(anim.at(index).frames.at(frame));
}

void SpriteObj::setTexture(sf::Texture texture)
{
	sprite.setTexture(texture);
}
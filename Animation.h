#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>
#include "SFML/Graphics.hpp"

class Animation
{
public:
	Animation();
	~Animation();

	std::vector<sf::IntRect> frames;
};

#endif
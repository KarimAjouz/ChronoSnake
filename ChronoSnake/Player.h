#pragma once

#include "Segment.h"

class Player
{
public:
	Player();
	~Player();

	void init();
	void update();
	void draw(sf::RenderWindow* window);

private:
	std::vector<Segment*> _segments;

	sf::Image* _snakeTexture;
};


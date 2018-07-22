#pragma once

#include "Segment.h"

class Player
{
public:
	Player();
	Player(sf::Vector2f pSpawn);

	~Player();

	void init();
	void update();
	void draw(sf::RenderWindow* window);

private:
	sf::Vector2f _levelSpawnLocation;

	std::vector<Segment*> _segments;

	sf::Image _snakeImage;

	bool _buttonPressed = false;

	void addSegment();
	void removeSegment();

	void testInputs();
};


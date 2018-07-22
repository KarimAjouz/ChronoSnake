#pragma once
#include <SFML\Graphics.hpp>

class Tile : public sf::RectangleShape
{
public:
	Tile();

	Tile(float tileSize);

	~Tile();

	void draw(sf::RenderWindow* window);

private:
};


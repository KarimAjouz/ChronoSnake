#include "Tile.h"



Tile::Tile()
{
}

Tile::Tile(float tileSize)
{
	this->setSize(sf::Vector2f(tileSize, tileSize));
}


Tile::~Tile()
{
}

void Tile::draw(sf::RenderWindow* window)
{
	window->draw(*this);
}
#pragma once

#include <iostream>
#include <vector>
#include <SFML\Graphics.hpp>

#include "Tile.h"

class Level
{
public:
	Level();
	~Level();

	void loadLevel(const std::string &fileName);

	void draw(sf::RenderWindow* window);
	void loadTextures();

	sf::Vector2f playerSpawn;


private: 
	std::vector<std::string> _levelData;

	std::vector<Tile*> _levelTiles;
	int _numMoves;

	sf::Texture _floorTexture;
	sf::Texture _wallTexture;
	sf::RectangleShape* _floorShape;
	sf::RectangleShape* _wallShape;


};


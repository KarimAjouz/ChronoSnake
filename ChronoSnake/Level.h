#pragma once

#include <iostream>
#include <vector>
#include <SFML\Graphics.hpp>

class Level
{
public:
	Level();
	~Level();

	void loadLevel(const std::string &fileName);

	void draw(sf::RenderWindow* window);
	void loadTextures();

private: 
	std::vector<std::string> _levelData;
	int _numMoves;

	sf::Texture _floorTexture;
	sf::Texture _wallTexture;
	sf::RectangleShape* _floorShape;
	sf::RectangleShape* _wallShape;


	sf::Vector2f _playerSpawn;
};


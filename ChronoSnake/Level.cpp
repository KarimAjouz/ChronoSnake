#include "Level.h"

#include <fstream>
#include <sstream>


Level::Level()
{
}


Level::~Level()
{
}


void Level::loadLevel(const std::string &fileName)
{
	std::ifstream file;
	file.open(fileName);

	if (file.fail())
	{
		std::cout << "Failed to Open Level: " << fileName << std::endl;
	}
	std::cout << "Level: " << fileName << " Loaded." << std::endl;

	//Toss first string;
	std::string tmp;
	file >> tmp >> _numMoves;

	while (std::getline(file, tmp))
	{
		_levelData.push_back(tmp);
	}

	for (int y = 0; y < _levelData.size(); y++)
	{
		for (int x = 0; x < _levelData[y].size(); x++)
		{
			char tile = _levelData[y][x];
			Tile* t = new Tile(64.0f);

			switch (tile)
			{
			case '#':
				//Draw the wall texture.
				t->setTexture(&_wallTexture);
				t->setPosition(64.0f * x, 64.0f * (y - 1));
				break;
			case '0':
				//Draw the floor texture.
				t->setTexture(&_floorTexture);
				t->setPosition(64.0f * x, 64.0f * (y - 1));
				break;
			case '@':
				//Draw the floor texture
				t->setTexture(&_floorTexture);
				t->setPosition(64.0f * x, 64.0f * (y - 1));
				//Set the player spawn point;
				playerSpawn.x = 64 * x;
				playerSpawn.y = 64 * y;
				break;
			default:
				//Draw the floor texture
				t->setTexture(&_floorTexture);
				t->setPosition(64.0f * x, 64.0f * (y - 1));
				break;
			}

			_levelTiles.push_back(t);
		}
	}
}

void Level::loadTextures()
{
	if (_floorTexture.loadFromFile("../Assets/Sprites/LevelSprites/defaultFloor.png"))
		std::cout << "Floor Texture Loaded." << std::endl;
	else
		std::cout << "Floor Texture could NOT be loaded." << std::endl;

	if (_wallTexture.loadFromFile("../Assets/Sprites/LevelSprites/defaultWall.png"))
		std::cout << "Wall Texture Loaded." << std::endl;
	else
		std::cout << "Wall Texture could NOT be loaded." << std::endl;
}

void Level::draw(sf::RenderWindow* window)
{
	
	for (int i = 0; i < _levelTiles.size(); i++)
	{
		_levelTiles[i]->draw(window);
	}
}
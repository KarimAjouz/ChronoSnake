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

	std::cout << std::endl << fileName << ": ";

	//Test print
	for (int i = 0; i < _levelData.size(); i++)
	{
		std::cout << _levelData[i] << std::endl;
	}
	
}

void Level::loadTextures()
{
	if (_floorTexture.loadFromFile("../Assets/Sprites/LevelSprites/defaultFloor.png"))
	{
		std::cout << "Floor Texture Loaded." << std::endl;
	}
	else
	{
		std::cout << "Floor Texture could NOT be loaded." << std::endl;
	}

	if (_wallTexture.loadFromFile("../Assets/Sprites/LevelSprites/defaultWall.png"))
	{
		std::cout << "Wall Texture Loaded." << std::endl;
	}
	else
	{
		std::cout << "Wall Texture could NOT be loaded." << std::endl;
	}
}

void Level::draw(sf::RenderWindow* window)
{
	for (int y = 0; y < _levelData.size(); y++)
	{
		for (int x = 0; x < _levelData[y].size(); x++)
		{
			char tile = _levelData[y][x];
			sf::RectangleShape rect(sf::Vector2f(64.0f, 64.0f));

			switch (tile)
			{
			case '#':
				//Draw the wall texture.
				rect.setTexture(&_wallTexture);
				rect.setPosition(64.0f * x, 64.0f * (y-1));
				break;
			case '0':
				//Draw the floor texture.
				rect.setTexture(&_floorTexture);
				rect.setPosition(64.0f * x, 64.0f * (y-1));
				break;
			case '@':
				//Set this as the spawn point for the player.
				_playerSpawn.x = 64 * x;
				_playerSpawn.y = 64 * y;
				rect.setTexture(&_floorTexture);
				rect.setPosition(64.0f * x, 64.0f * (y - 1));
				//Draw the floor texture
				break;
			default:
				break;
			}

			window->draw(rect);
		}
	}
}
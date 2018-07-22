#include "MainGame.h"

#include "MainMenu.h"



MainGame::MainGame()
{
}


MainGame::~MainGame()
{
}

void MainGame::init(sf::RenderWindow* window)
{
	std::cout << "Initialising main game" << std::endl;

	Level* l = new Level();
	l->loadLevel("../Assets/Levels/level1.txt");
	l->loadTextures();
	_levels.push_back(l);

	_player = new Player(l->playerSpawn);
	_player->init();
	

}

void MainGame::update(sf::RenderWindow* window)
{
	_player->update();
}

void MainGame::render(sf::RenderWindow* window)
{
	_levels[0]->draw(window);
	_player->draw(window);
}

void MainGame::destroy(sf::RenderWindow* window)
{
	for (int i = 0; i < _levels.size(); i++)
	{
		delete(_levels[i]);
	}
}

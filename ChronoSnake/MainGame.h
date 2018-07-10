#pragma once

#include "GameState.h"
#include "Level.h"
#include "Player.h"

class MainGame : public TinyState
{
public:
	MainGame();
	~MainGame();

	void init(sf::RenderWindow* window);
	void update(sf::RenderWindow* window);
	void render(sf::RenderWindow* window);
	void destroy(sf::RenderWindow* window);

private:
	std::vector<Level*> _levels; ///< vector of all the levels.
	Player* _player;


	int curLevel = 0;
};
#include "Player.h"



Player::Player()
{
}


Player::~Player()
{
}

void Player::init()
{
	_snakeTexture = new sf::Image();
	_snakeTexture->loadFromFile("../Assets/Sprites/SnakeSprite/midSnake.png");
	_segments.push_back(new Segment(_snakeTexture));
}

void Player::update()
{

}

void Player::draw(sf::RenderWindow* window)
{
	for (int i = 0; i < _segments.size(); i++)
	{
		_segments[i]->draw(window);
	}
}
#include "Player.h"

#include <SFML\Main.hpp>



Player::Player()
{
}

Player::Player(sf::Vector2f pSpawn)
{
	_levelSpawnLocation = pSpawn;
}


Player::~Player()
{
}

void Player::init()
{
	_snakeImage.loadFromFile("../Assets/Sprites/SnakeSprite/snake.png");
	_segments.push_back(new Segment(_snakeImage));
	_segments[0]->setPosition(_levelSpawnLocation);
}

void Player::update()
{
	testInputs();
}

void Player::draw(sf::RenderWindow* window)
{
	for (int i = 0; i < _segments.size(); i++)
	{
		_segments[i]->draw(window);
	}
}

void Player::addSegment()
{
	_segments.push_back(new Segment(_segments[_segments.size() - 1]));
}

void Player::removeSegment()
{
	if(_segments.size() > 1)
		_segments.pop_back();
}

void Player::testInputs()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !_buttonPressed)
	{
		(_segments[0]->moveSegment(sf::Vector2f(0.0f, -1.0f)));
		_buttonPressed = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !_buttonPressed)
	{
		(_segments[0]->moveSegment(sf::Vector2f(0.0f, 1.0f)));
		_buttonPressed = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !_buttonPressed)
	{
		(_segments[0]->moveSegment(sf::Vector2f(-1.0f, 0.0f)));
		_buttonPressed = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !_buttonPressed)
	{
		(_segments[0]->moveSegment(sf::Vector2f(1.0f, 0.0f)));
		_buttonPressed = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !_buttonPressed)
	{
		removeSegment();
		_buttonPressed = true;
	}
	else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::E) && !_buttonPressed))
	{
		addSegment();
		_buttonPressed = true;
	}

	//Simple test to check if I need to allow another button to be pressed.
	if (
		!sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::A) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::Q) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::E)	)
	{
		_buttonPressed = false;
	}
	
}
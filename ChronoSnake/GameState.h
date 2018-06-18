#pragma once

#include <SFML\graphics.hpp>

class TinyState
{
public:
	virtual void init(sf::RenderWindow* window)
	{

	}

	virtual void update(sf::RenderWindow* window)
	{

	}

	virtual void render(sf::RenderWindow* window)
	{

	}

	virtual void destroy(sf::RenderWindow* window)
	{

	}

	~TinyState()
	{

	}
};

class GameState
{
public:
	GameState()
	{
		this->_state = NULL;
	}

	void setWindow(sf::RenderWindow* window)
	{
		this->_window = window;
	}

	void setState(TinyState* state)
	{
		if (this->_state != NULL)
		{
			this->_state->destroy(this->_window);
		}

		this->_state = state;

		if (this->_state != NULL)
		{
			this->_state->init(this->_window);
		}
	}

	void update()
	{
		if (this->_state != NULL)
		{
			this->_state->update(this->_window);
		}
	}
	void render()
	{
		if (this->_state != NULL)
		{
			this->_state->render(this->_window);
		}
	}

	~GameState()
	{
		if (this->_state != NULL)
		{
			this->_state->destroy(this->_window);
		}
	}
private:
	sf::RenderWindow* _window;
	TinyState* _state;
};

extern GameState coreState;
extern bool quitGame;
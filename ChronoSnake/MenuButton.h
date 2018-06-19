#pragma once

#include "GameState.h"

#include <SFML/Graphics.hpp>


class MenuButton
{
public:
	MenuButton(sf::RenderWindow* window, int relativePosition, sf::Font* font, sf::String buttonText);
	~MenuButton();

	void update(sf::RenderWindow* window);
	void draw(sf::RenderWindow* window);

private:

	sf::Text* _buttonText;

	int _buttonPadding = 10;

	bool _mPressed;
};


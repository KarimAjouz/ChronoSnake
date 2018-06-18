#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.h"

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


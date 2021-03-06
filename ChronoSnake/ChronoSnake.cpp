#pragma once
#include "MainMenu.h"

#include <SFML/Graphics.hpp>

GameState coreState;
bool quitGame = false;

int main()
{
	sf::RenderWindow window(sf::VideoMode(960, 640), "proj v0.0.1"); 

	coreState.setWindow(&window);
	coreState.setState(new MainMenu());

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear(sf::Color::Black);

		coreState.update();
		coreState.render();

		window.display();

		if (quitGame)
			window.close();
	}

	return 0;
}
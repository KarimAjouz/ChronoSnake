#pragma once

#include "GameState.h"
#include "MenuButton.h"

#include <vector>

class MainMenu : public TinyState
{
public:
	MainMenu();
	~MainMenu();

	void init(sf::RenderWindow* window);
	void update(sf::RenderWindow* window);
	void render(sf::RenderWindow* window);
	void destroy(sf::RenderWindow* window);

private:
	sf::Font* _font;
	sf::Text* _title;
	MenuButton* _playButton;
	MenuButton* _quitButton;

	int _buttonPadding = 10;

	std::vector<MenuButton*> _buttons;

};


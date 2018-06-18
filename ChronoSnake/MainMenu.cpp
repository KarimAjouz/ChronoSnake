#include "MainMenu.h"

#include <iostream>


MainMenu::MainMenu()
{

}


MainMenu::~MainMenu()
{
}

void MainMenu::init(sf::RenderWindow* window)
{
	this->_font = new sf::Font();
	this->_font->loadFromFile("../Assets/Fonts/squares/Squares_Bold_Free.otf");

	this->_title = new sf::Text("SnakeTime", *this->_font, 64U);
	this->_title->setOrigin(this->_title->getGlobalBounds().width / 2, this->_title->getGlobalBounds().height / 2);
	this->_title->setPosition(window->getSize().x / 2, window->getSize().y / 6);

	_playButton = new MenuButton(window, 2, this->_font, "Play");
	_quitButton = new MenuButton(window, 5, this->_font, "Quit");


	_buttons.push_back(_playButton);
	_buttons.push_back(_quitButton);


	std::cout << "Initiated\n";


	sf::Mouse::setPosition(sf::Vector2i(window->getSize().x / 2, window->getSize().y / 2), *window);
}

void MainMenu::update(sf::RenderWindow* window)
{
	for (int i = 0; i < _buttons.size(); i++)
	{
		_buttons[i]->update(window);
	}
}

void MainMenu::render(sf::RenderWindow* window)
{
	window->draw(*this->_title);

	for (int i = 0; i < _buttons.size(); i++)
	{
		_buttons[i]->draw(window);
	}
}

void MainMenu::destroy(sf::RenderWindow* window)
{
	delete this->_title;
	delete this->_playButton;
	delete this->_quitButton;

	delete this->_font;

	std::cout << "Destroyed\n";
}


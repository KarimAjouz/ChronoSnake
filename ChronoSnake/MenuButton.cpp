#include "MenuButton.h"

#include "MainGame.h"
#include "GameState.h"

#include <iostream>

		/*
		Constructor for the menu button class. 
		Class handles creation of up to four Menu Buttons that line down the center of the page.
		Window is a pointer to the game window.
		Relative Position is an int 1-6 that places the button evenly along the center y axis. 
		Font is a pointer to the font we are using.
		Button Text is the text that the button needs to display.
		*/
MenuButton::MenuButton(sf::RenderWindow* window, int relativePosition, sf::Font* font, sf::String buttonText)
{
	this->_buttonText = new sf::Text(buttonText, *font, 24U);
	this->_buttonText->setOrigin(this->_buttonText->getGlobalBounds().width / 2, this->_buttonText->getGlobalBounds().height / 2);
	this->_buttonText->setPosition(window->getSize().x / 2, window->getSize().y / 6 * relativePosition);
}


MenuButton::~MenuButton()
{
}

/*
This function checks to see if the mouse is hovering over/clicking the button.
*/
void MenuButton::update(sf::RenderWindow * window)
{
	//First we get the Mouse position relative to the window.
	sf::Vector2i mPos = sf::Mouse::getPosition(*window);

	//AABB Collision detection from button-Mouse.
	if (
		mPos.x > _buttonText->getGlobalBounds().left - _buttonPadding &&
		mPos.x < _buttonText->getGlobalBounds().left + _buttonText->getGlobalBounds().width + _buttonPadding &&
		mPos.y > _buttonText->getGlobalBounds().top - _buttonPadding &&
		mPos.y < _buttonText->getGlobalBounds().top + _buttonText->getGlobalBounds().height + _buttonPadding
		)
	{
		//If collide change text colour.
		_buttonText->setFillColor(sf::Color::Red);

		//Test Click
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !_mPressed)
		{
			if (_buttonText->getString() == "Quit")
			{
				quitGame = true;
			}

			if (_buttonText->getString() == "Play")
			{
				std::cout << std::string(_buttonText->getString()) << " button was pressed" << std::endl;
				coreState.setState(new MainGame());
			}

			_mPressed = true;
		}
		else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && _mPressed)
		{
			//Boolean Fix
			_mPressed = false;
		}


	}
	else
	{
		_buttonText->setFillColor(sf::Color::White);
	}
}

void MenuButton::draw(sf::RenderWindow* window)
{
	window->draw(*_buttonText);
}



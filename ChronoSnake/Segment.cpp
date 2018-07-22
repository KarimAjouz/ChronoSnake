#include "Segment.h"
#include <iostream>



Segment::Segment()
{
}

Segment::Segment(sf::Image snakeTex)
{
	this->_snakeTex = snakeTex;
	
	if (_frontSegmentTexture.loadFromImage(snakeTex, sf::IntRect(0, 0, 64, 64)))
		std::cout << "FrontSegmentTex loaded" << std::endl;
	else 
		std::cout << "FrontSegmentTex could NOT be loaded" << std::endl;

	if(_backSegmentTexture.loadFromImage(snakeTex, sf::IntRect(64, 0, 64, 64)))
		std::cout << "BackSegmentTex loaded" << std::endl;
	else
		std::cout << "BackSegmentTex could NOT be loaded" << std::endl;

	if(_cornerSegmentTexture.loadFromImage(snakeTex, sf::IntRect(128, 0, 64, 64)))
		std::cout << "CornerSegmentTex loaded" << std::endl;
	else
		std::cout << "CornerSegmentTex could NOT be loaded" << std::endl;

	if(_middleSegmentTexture.loadFromImage(snakeTex, sf::IntRect(192, 0, 64, 64)))
		std::cout << "MidSegmentTex loaded" << std::endl;
	else
		std::cout << "MidSegmentTex could NOT be loaded" << std::endl;

}

Segment::Segment(Segment* segInFront)
{
   	_segInFront = segInFront;
	segInFront->_segBehind = this;
	_segBehind = NULL;

	_frontSegmentTexture = segInFront->_frontSegmentTexture;
	_backSegmentTexture = segInFront->_backSegmentTexture;
	_cornerSegmentTexture = segInFront->_cornerSegmentTexture;
	_middleSegmentTexture = segInFront->_middleSegmentTexture;


	if (segInFront->_currentRotation == 0)
	{
		this->setPosition(segInFront->getPosition() + (sf::Vector2f(0, 1) * _spriteSize));
	}
	else if (segInFront->_currentRotation == 90)
	{
		this->setPosition(segInFront->getPosition() + (sf::Vector2f(-1, 0) * _spriteSize));
	}
	else if (segInFront->_currentRotation == 180)
	{
		this->setPosition(segInFront->getPosition() + (sf::Vector2f(0, -1) * _spriteSize));
	}
	else if (segInFront->_currentRotation == 270)
	{
		this->setPosition(segInFront->getPosition() + (sf::Vector2f(1, 0) * _spriteSize));
	}

}

Segment::~Segment()
{
}

//Simple function to decide which texture to use.
void Segment::textureDecider()
{
	if (this->_segInFront == NULL) 
	{
		this->setTexture(_frontSegmentTexture);
	}
	else if (this->_segBehind == NULL)
	{
		this->setTexture(_backSegmentTexture);
	}
	else if (_segInFront->getPosition().x == _segBehind->getPosition().x || _segInFront->getPosition().y == _segBehind->getPosition().y)
	{
		this->setTexture(_middleSegmentTexture);
	}
	else
	{
		this->setTexture(_cornerSegmentTexture);
	}
}

//Moves the foremost segment, calls the next segment to take the place of this one.
void Segment::moveSegment(sf::Vector2f direction)
{
	if (this->_segBehind != NULL)
		this->_segBehind->moveSegment();

	if (direction.x > 0)
	{
		moveRight();
	}
	else if (direction.x < 0)
	{
		moveLeft();
	}
	else if (direction.y > 0)
	{
		moveDown();
	}
	else if (direction.y < 0)
	{
		moveUp();
	}

}

//Moves the segment to the previous position of the segment ahead. 
//NOTE: ONLY get's called from within this class.
void Segment::moveSegment()
{	//Tests to see if there is a segment behind this one. Recursively calls the function if there is.
	if (this->_segBehind != NULL)
		this->_segBehind->moveSegment();

	this->setPosition(this->_segInFront->getPosition());
}



//Code is used when the player moves backwards. Moves the end segment back one space, makes all other segments follow suit.
void Segment::moveBackwards()
{
	if (this->_segBehind == NULL)
	{
		if(this->_currentRotation == 0)
			this->setPosition(this->getPosition() + sf::Vector2f(0, 1) * _spriteSize);
		else if (this->_currentRotation == 90)
			this->setPosition(this->getPosition() + sf::Vector2f(-1, 0) * _spriteSize);
		else if (this->_currentRotation == 180)
			this->setPosition(this->getPosition() + sf::Vector2f(0, -1) * _spriteSize);
		else if (this->_currentRotation == 270)
			this->setPosition(this->getPosition() + sf::Vector2f(1, 0) * _spriteSize);
	}
	else
	{
		this->setPosition(this->_segBehind->getPosition());
	}

	if(this->_segInFront != NULL)
		this->_segInFront->moveBackwards();
}

void Segment::draw(sf::RenderWindow* window)
{
	textureDecider();
	window->draw(*this);
}

void Segment::moveUp()
{
	if (_currentRotation != 180)
	{
		this->setPosition(this->getPosition() + sf::Vector2f(0.0f, -1.0f) * _spriteSize);
		_currentRotation = 0;
	}
	else
	{
		moveBackwards();
	}
}

void Segment::moveDown()
{
	if (_currentRotation != 0)
	{
		this->setPosition(this->getPosition() + sf::Vector2f(0.0f, 1.0f) * _spriteSize);
		_currentRotation = 180;
	}
	else
	{
		moveBackwards();
	}
}

void Segment::moveLeft()
{
	if (_currentRotation != 90)
	{
		this->setPosition(this->getPosition() + sf::Vector2f(-1.0f, 0.0f) * _spriteSize);
		_currentRotation = 270;
	}
	else
	{
		moveBackwards();
	}
}

void Segment::moveRight()
{
	if (_currentRotation != 270)
	{
		this->setPosition(this->getPosition() + sf::Vector2f(1.0f, 0.0f) * _spriteSize);
		_currentRotation = 90;
	}
	else
	{
		moveBackwards();
	}
}
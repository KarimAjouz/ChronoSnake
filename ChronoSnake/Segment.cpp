#include "Segment.h"



Segment::Segment()
{
}

Segment::Segment(sf::Image* snakeTex)
{
	this->_snakeTex = snakeTex;
	
	this->_frontSegmentTexture->loadFromImage(*this->_snakeTex, sf::IntRect(0, 0, 64, 64));
	this->_backSegmentTexture->loadFromImage(*this->_snakeTex, sf::IntRect(64, 0, 128, 64));
	this->_cornerSegmentTexture->loadFromImage(*this->_snakeTex, sf::IntRect(128, 0, 192, 64));
	this->_middleSegmentTexture->loadFromImage(*this->_snakeTex, sf::IntRect(192, 0, 256, 64));
}

Segment::~Segment()
{
}

//Simple function to decide which texture to use.
void Segment::textureDecider()
{
	if (this->_segInFront == NULL) 
	{
		this->setTexture(*_frontSegmentTexture);
	}
	else if (_segInFront->_relPosToNextSeg == this->_relPosToNextSeg)
	{
		this->setTexture(*_middleSegmentTexture);
	}
	else if (this->_segBehind == NULL)
	{
		this->setTexture(*_backSegmentTexture);
	}
	else
	{
		this->setTexture(*_cornerSegmentTexture);
	}
}

//Moves the foremost segment, calls the next segment to take the place of this one.
void Segment::moveSegment(sf::Vector2f direction)
{
	this->setPosition(this->getPosition() + direction * _spriteSize);
	if (this->_segBehind != NULL)
		this->_segBehind->moveSegment();
}

//Code is used when the player moves backwards. Moves the end segment back one space, makes all other segments follow suit.
void Segment::moveBackwards()
{
	if (this->_segBehind == NULL)
	{
		if(this->_currentRotation == 0)
			this->setPosition(this->getPosition() + sf::Vector2f(0, -1) * _spriteSize);
		else if (this->_currentRotation == 90)
			this->setPosition(this->getPosition() + sf::Vector2f(-1, 0) * _spriteSize);
		else if (this->_currentRotation == 180)
			this->setPosition(this->getPosition() + sf::Vector2f(0, 1) * _spriteSize);
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

//Moves the segment to the previous position of the segment ahead. 
//NOTE: ONLY get's called from within this class.
void Segment::moveSegment()
{
	this->setPosition(this->_segInFront->getPosition());
	if(this->_segBehind != NULL)
		this->_segBehind->moveSegment();
}


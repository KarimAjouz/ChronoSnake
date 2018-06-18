#include "Segment.h"



Segment::Segment()
{
}

Segment::Segment
(
	sf::Texture* frontSegmentTexture,
	sf::Texture* backSegmentTexture,
	sf::Texture* cornerSegmentTexture,
	sf::Texture* middleSegmentTexture
)
{
	this->_frontSegmentTexture  =  frontSegmentTexture;
	this->_backSegmentTexture   =   backSegmentTexture;
	this->_cornerSegmentTexture = cornerSegmentTexture;
	this->_middleSegmentTexture = middleSegmentTexture;
}

Segment::~Segment()
{
}

//Simple function to decide which texture to use.
void Segment::textureDecider()
{
	if (this->_segInFront != NULL) 
	{
		_segment->setTexture(*_frontSegmentTexture);
	}
	else if (_segInFront->_relPosToNextSeg == this->_relPosToNextSeg)
	{
		_segment->setTexture(*_middleSegmentTexture);
	}
	else if (this->_relPosToNextSeg == sf::Vector2i(0, 0))
	{
		_segment->setTexture(*_backSegmentTexture);
	}
	else
	{
		_segment->setTexture(*_cornerSegmentTexture);
	}
}

//Moves the foremost segment, calls the next segment to take the place of this one.
void Segment::moveSegment(sf::Vector2f direction)
{
	this->_segment->setPosition(this->_segment->getPosition() + direction * _spriteSize);
	if (this->_segBehind != NULL)
		this->_segBehind->moveSegment();
}

//Code is used when the player moves backwards. Moves the end segment back one space, makes all other segments follow suit.
void Segment::moveBackwards()
{
	if (this->_segBehind == NULL)
	{
		if(this->_currentRotation == 0)
			this->_segment->setPosition(this->_segment->getPosition() + sf::Vector2f(0, -1) * _spriteSize);
		else if (this->_currentRotation == 90)
			this->_segment->setPosition(this->_segment->getPosition() + sf::Vector2f(-1, 0) * _spriteSize);
		else if (this->_currentRotation == 180)
			this->_segment->setPosition(this->_segment->getPosition() + sf::Vector2f(0, 1) * _spriteSize);
		else if (this->_currentRotation == 270)
			this->_segment->setPosition(this->_segment->getPosition() + sf::Vector2f(1, 0) * _spriteSize);
	}
	else
	{
		this->_segment->setPosition(this->_segBehind->_segment->getPosition());
	}

	if(this->_segInFront != NULL)
		this->_segInFront->moveBackwards();
}

//Moves the segment to the previous position of the segment ahead. 
//NOTE: ONLY get's called from within this class.
void Segment::moveSegment()
{
	this->_segment->setPosition(_segInFront->_segment->getPosition());
	if(this->_segBehind != NULL)
		this->_segBehind->moveSegment();
}


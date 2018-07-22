#pragma once

#include <SFML/Graphics.hpp>

class Segment : public sf::Sprite
{
public:
	Segment();
	Segment(sf::Image snakeTex);
	Segment(Segment* segInFront);

	~Segment();

	void moveSegment(sf::Vector2f direction);
	void moveBackwards();
	void draw(sf::RenderWindow* window);

private:
	float _spriteSize = 64.0f;

	sf::Vector2i _relPosToNextSeg = sf::Vector2i(0, 0);

	sf::Image _snakeTex;

	sf::Texture _frontSegmentTexture;
	sf::Texture _backSegmentTexture;
	sf::Texture _cornerSegmentTexture;
	sf::Texture _middleSegmentTexture;

	Segment* _segInFront;
	Segment* _segBehind = NULL;

	float _currentRotation = 0;

	void textureDecider();

	void moveSegment();

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
};


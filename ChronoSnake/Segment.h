#pragma once

#include <SFML/Graphics.hpp>

class Segment
{
public:
	Segment();
	Segment(
		sf::Texture* frontSegmentTexture,
		sf::Texture* backSegmentTexture,
		sf::Texture* cornerSegmentTexture,
		sf::Texture* middleSegmentTexture
	);

	~Segment();

	void moveSegment(sf::Vector2f direction);
	void moveBackwards();


private:
	float _spriteSize = 64.0f;

	sf::Vector2i _relPosToNextSeg = sf::Vector2i(0, 0);

	sf::Texture* _frontSegmentTexture;
	sf::Texture* _backSegmentTexture;
	sf::Texture* _cornerSegmentTexture;
	sf::Texture* _middleSegmentTexture;

	sf::Sprite* _segment;

	Segment* _segInFront;
	Segment* _segBehind = NULL;

	float _currentRotation;

	void textureDecider();

	void moveSegment();
};


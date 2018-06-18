#pragma once

#include "Segment.h"

class Player
{
public:
	Player();
	~Player();

private:
	std::vector<Segment*> _segments;
};


#pragma once
#include "Block.hpp"

class BlockX :public Block
{
public:
	BlockX(sf::Vector2f blockSize, sf::Vector2f blockPosition);
	bool isSet = 0;
	void mark();
};
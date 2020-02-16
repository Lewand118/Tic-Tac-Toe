#pragma once
#include "Block.hpp"

class BlockO :public Block
{
public:
	BlockO(sf::Vector2f blockSize, sf::Vector2f blockPosition);
	bool isSet = 0;
	void mark();
};
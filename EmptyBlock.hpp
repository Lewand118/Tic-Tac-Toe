#pragma once
#include "Block.hpp"

class EmptyBlock :public Block
{
public:
	EmptyBlock(sf::Vector2f blockSize, sf::Vector2f blockPosition);
};


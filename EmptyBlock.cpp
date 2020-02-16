#include "EmptyBlock.hpp"

EmptyBlock::EmptyBlock(sf::Vector2f blockSize, sf::Vector2f blockPosition)
{
	texture.loadFromFile(".\\textures\\block.png");
	block.setTexture(&texture);
	block.setSize(blockSize);
	block.setPosition(blockPosition);
}

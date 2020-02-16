#include "Block.hpp"

void Block::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(block);
}

#include "BlockX.hpp"

BlockX::BlockX(sf::Vector2f blockSize, sf::Vector2f blockPosition)
{
	texture.loadFromFile("D:\\programowanie\\Programowanie_projekty\\SFML\\Kó³ko i krzy¿yk\\Tic Tac Toe\\textures\\X.png");
	block.setTexture(&texture);
	block.setSize(blockSize);
	block.setPosition(blockPosition);
}

void BlockX::mark()
{
	block.setFillColor(sf::Color::Yellow);
}
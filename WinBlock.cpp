#include "WinBlock.hpp"

WinBlock::WinBlock(int who)
	:who(who)
{
	if (who == 1) // X
		texture.loadFromFile("D:\\programowanie\\Programowanie_projekty\\SFML\\Kó³ko i krzy¿yk\\Tic Tac Toe\\textures\\Xwon.png");
	else if (who == 0)
		texture.loadFromFile("D:\\programowanie\\Programowanie_projekty\\SFML\\Kó³ko i krzy¿yk\\Tic Tac Toe\\textures\\Owon.png");
	else
		texture.loadFromFile("D:\\programowanie\\Programowanie_projekty\\SFML\\Kó³ko i krzy¿yk\\Tic Tac Toe\\textures\\draw.png");
	block.setTexture(&texture);
	block.setSize({390, 130});
	block.setPosition({0, 0});
	block.setFillColor(sf::Color::Yellow);
}


#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <vector>
#include "Block.hpp"
#include "BlockX.hpp"
#include "BlockO.hpp"
#include "EmptyBlock.hpp"
#include "WinBlock.hpp"

#include <iostream>
#include <Windows.h>
#include <ctime>

class Window
{
	sf::RenderWindow window;
	std::vector<std::vector<Block*>> Board;
	sf::Vector2f blockSize;
	sf::Vector2i whichClicked{ -1,-1 };
	bool tour; // true - X, false - O
	int **positionMatrix; // 0 - empty, 1 - X, -1 - O, -2 - already set
	int result = -3; // 1 - X won, 0 - O won, -2 - draw, -3 - nothing
	bool gameOver = false;

public:
	Window(sf::Vector2f windowSize, sf::Vector2f matrixSize);
	~Window();
	sf::Vector2i click();
	void update(sf::Vector2i position);
	void randomStart();
	void whoWon(int** positionMatrix); // true - X, false - O
	void printOver();
	void playAgain();

	void run();
};


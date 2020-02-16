#include "Window.hpp"

Window::Window(sf::Vector2f windowSize, sf::Vector2f matrixSize)
	:window(sf::VideoMode((unsigned int) windowSize.x, (unsigned int)windowSize.y), "Tic Tac Toe", sf::Style::Default),
	Board(matrixSize.x), blockSize{ (float)(windowSize.x / matrixSize.x), (float)(windowSize.y / matrixSize.y) }
{
	for (int i = 0; i < Board.size(); i++)
	{
		Board[i].resize((int)matrixSize.y);
		for (int j = 0; j < Board[i].size(); j++)
			Board[i][j] = new EmptyBlock(blockSize, { i * blockSize.x, j * blockSize.y }); // rysuje w dol - kolumnami, pod wyswietlanie
	}

	positionMatrix = new int* [(int)matrixSize.x];
	for (int i = 0; i < (int)matrixSize.x; i++)
	{
		positionMatrix[i] = new int[(int)matrixSize.y];
		for (int j = 0; j < (int)matrixSize.y; j++)
			positionMatrix[i][j] = 0;
	}
}

Window::~Window()
{
}

void Window::run()
{
	srand(time(NULL));
	randomStart();
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);
	while (window.isOpen())
	{
		window.clear();
		if (!gameOver)
		{
			sf::Event e;
			while (window.pollEvent(e))
			{
				if (e.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					window.close();

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					click();

				if (whichClicked.x != -1 && whichClicked.y != -1)
					update(whichClicked);

			}
			
			for (auto& col : Board)
				for (auto& cell : col)
					window.draw(*cell);

			whoWon(positionMatrix);
		}
		else
		{
			printOver();
			sf::Event e;
			while (window.pollEvent(e))
			{
				if (e.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					window.close();
				if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
					playAgain();
			}
		}
		window.display();
	}
}

sf::Vector2i Window::click()
{
	for (int i = 0; i < Board.size(); i++)
	{
		for (int j = 0; j < Board[i].size(); j++)
		{
			if (sf::Mouse::getPosition(window).x > i * blockSize.x && sf::Mouse::getPosition(window).x < i * blockSize.x + blockSize.x
				&& sf::Mouse::getPosition(window).y > j * blockSize.y && sf::Mouse::getPosition(window).y < j * blockSize.y + blockSize.y)
			{
				whichClicked = { i,j };
			}
		}
	}
	return whichClicked;
}

void Window::update(sf::Vector2i position)
{
	if (positionMatrix[position.x][position.y] == 0)
	{
		if (tour)
		{
			delete Board[position.x][position.y];
			Board[position.x][position.y] = new BlockX(blockSize, { position.x * blockSize.x, position.y * blockSize.y });
			positionMatrix[position.x][position.y] = 1;
			tour = 0;
		}
		else
		{
			delete Board[position.x][position.y];
			Board[position.x][position.y] = new BlockO(blockSize, { position.x * blockSize.x, position.y * blockSize.y });
			positionMatrix[position.x][position.y] = -1;
			tour = 1;
		}
	}
}

void Window::randomStart()
{
	tour = (rand() % 2);
}

void Window::whoWon(int** positionMatrix)
{
	for (int i = 0; i < Board.size(); i++) // vertical
	{
		int ctr = 0, k = 0;
		if (positionMatrix[i][0] == 1) // X
			while (k < Board[i].size() && positionMatrix[i][0] == positionMatrix[i][k++])
				ctr++;
		else if (positionMatrix[i][0] == -1) // O
			while (k < Board[i].size() && positionMatrix[i][0] == positionMatrix[i][k++])
				ctr++;
		if (ctr == Board[i].size())
		{
			if (positionMatrix[i][0] == 1)
				result = 1;
			else
				result = 0;
			//for(int j = 0; j < Board.size(); j++)
			//	Board.at(i).&at(j);
			break;
		}
	}

	for (int i = 0; i < Board.size(); i++) // horizontal
	{
		int ctr = 0, k = 0;
		if (positionMatrix[0][i] == 1) // X
			while (k < Board.size() && positionMatrix[0][i] == positionMatrix[k++][i])
				ctr++;
		else if (positionMatrix[0][i] == -1) // O
			while (k < Board.size() && positionMatrix[0][i] == positionMatrix[k++][i])
				ctr++;
		if (ctr == Board.size())
		{
			if (positionMatrix[0][i] == 1)
				result = 1;
			else
				result = 0;
			break;
		}
	}

	int k = 0, p = 0, ctr = 0; // across
	if (positionMatrix[0][0] == 1) // X
		while (k < Board.size() && p < Board.size() && positionMatrix[0][0] == positionMatrix[k++][p++])
			ctr++;
	else if (positionMatrix[0][0] == -1) // O
		while (k < Board.size() && p < Board.size() && positionMatrix[0][0] == positionMatrix[k++][p++])
			ctr++;
	if (ctr == Board.size())
	{
		if (positionMatrix[0][0] == 1)
			result = 1;
		else
			result = 0;
	}

	k = (Board.size() - 1), p = 0, ctr = 0; // across
	if (positionMatrix[(int)(Board.size()-1)][0] == 1) // X
		while (k >= 0 && p < Board.size() && positionMatrix[(int)(Board.size() - 1)][0] == positionMatrix[k--][p++])
			ctr++;
	else if (positionMatrix[(int)(Board.size() - 1)][0] == -1) // O
		while (k >= 0 && p < Board.size() && positionMatrix[(int)(Board.size() - 1)][0] == positionMatrix[k--][p++])
			ctr++;
	if (ctr == Board.size())
	{
		if (positionMatrix[(int)(Board.size() - 1)][0] == 1)
			result = 1;
		else
			result = 0;
	}

	int empty_ctr = 0;
	for (int i = 0; i < Board.size(); i++)
		for (int j = 0; j < Board[i].size(); j++)
			if (positionMatrix[i][j] == 0)
				empty_ctr++;

	if (empty_ctr == 0 && result == -3)
		result = -2;


	/*if (result == 1)
		std::cout << "X won\n";
	else if (result == 0)
		std::cout << "O won\n";
	else if (result == -2)
		std::cout << "draw\n";*/
	if (result != -3)
		gameOver = true;
}

void Window::printOver()
{
	WinBlock wBlock(result);
	for (auto& col : Board)
		for (auto& cell : col)
			window.draw(*cell);
	window.draw(wBlock);
}

void Window::playAgain()
{
	gameOver = false;
	for (int i = 0; i < Board.size(); i++)
	{
		for (int j = 0; j < Board[i].size(); j++)
		{
			delete Board[i][j];
			Board[i][j] = new EmptyBlock(blockSize, { i * blockSize.x, j * blockSize.y });
			positionMatrix[i][j] = 0;
		}
	}
	result = -3;
	whichClicked = { -1,-1 };
	window.clear();
	randomStart();
}
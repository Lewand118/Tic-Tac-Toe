#pragma once
#include "SFML/Graphics.hpp"
#include "Block.hpp"

class WinBlock :public Block
{
	int who; // 1 - X, 0 - O
public:
	WinBlock(int who);
};


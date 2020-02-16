#include "Window.hpp"

int main()
{
	Window window(sf::Vector2f{800, 800}, sf::Vector2f{3, 3});

	window.run();

	return 0;
}
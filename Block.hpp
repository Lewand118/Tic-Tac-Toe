#pragma once
#include "SFML/Graphics.hpp"

class Block :public sf::Drawable
{
protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Texture texture;
	sf::RectangleShape block;
};


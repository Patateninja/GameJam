#pragma once
#include "tools.h"

namespace Mouse
{
	void updateMousePosition(sf::RenderWindow& _window);

	sf::Vector2f getMousePos();

	sf::Vector2i getMousePosI();

	sf::Vector2f getRelativeMousePos();

	sf::Vector2i getRelativeMousePosI();

}
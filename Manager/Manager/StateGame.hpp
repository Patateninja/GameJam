#pragma once
#include "SFML/Graphics.hpp"

namespace StateGame
{
	void Init();
	void Update();
	void Display(sf::RenderWindow& _window);
	void DeInit();
};
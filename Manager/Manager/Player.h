#pragma once

#include "Tools.h"
#include "Ennemy.hpp"


namespace Player
{
	float GetPlayerSpeed();
	void SetPlayerSpeed(float value);

	float GetRotateSpeed();
	void SetRotateSpeed(float value);

	sf::Vector2f GetPlayerPosition();
	float GetPlayerRotation();

	void Init();

	void Update();

	void Display(sf::RenderWindow& _window);
}
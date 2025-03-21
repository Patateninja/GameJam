#pragma once

#include "tools.h"


namespace Player
{
	float GetPlayerSpeed();
	void SetPlayerSpeed(float value);

	float GetRotateSpeed();
	void SetRotateSpeed(float value);

	void Init();

	void Update();

	void Display(sf::RenderWindow& _window);

}
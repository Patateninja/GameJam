#pragma once

#include "Tools.h"
#include "Ennemy.hpp"

class Enemy;

namespace Player
{
	float GetPlayerSpeed();
	void SetPlayerSpeed(float value);

	float GetRotateSpeed();
	void SetRotateSpeed(float value);
	void setTeslaState(const bool state);

	sf::Vector2f GetPlayerPosition();
	float GetPlayerRotation();

	void Init();

	void Update(std::list<Enemy*>& _EnemyList);

	void Hurt(float _amount);

	void Display(sf::RenderWindow& _window);
}
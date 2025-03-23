#pragma once

#include "tools.h"
#include "Ennemy.hpp"

class Enemmy;

namespace Ultime
{
	void InitUltime();

	void UpdateUltime(std::list<Enemy*> _EnemyList);

	void DisplayUltime(sf::RenderWindow& _window);

	bool GetFirstPass();

	void SetFirstPass(bool _firstPass);

	void SetStateUltime(bool _state);
}
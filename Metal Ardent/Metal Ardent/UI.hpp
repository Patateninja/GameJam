#pragma once
#include "tools.hpp"

namespace UI
{
	bool GetKeyStartUlt();
	void SetKeyStartUlt(bool _keyStartUlt);
	void Init();
	void Update(int _playerHP);
	void Display(sf::RenderWindow& _window);

	void SmallShot();
	void BigShot();

	bool canSmallShot();
	bool canBigShot();

	void KillEnemy();
}


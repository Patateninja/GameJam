#pragma once

#include "tools.h"

namespace Ultime
{
	void InitUltime();

	void UpdateUltime();

	void DisplayUltime(sf::RenderWindow& _window);

	bool GetFirstPass();

	void SetFirstPass(bool _firstPass);

	void SetStateUltime(bool _state);
}
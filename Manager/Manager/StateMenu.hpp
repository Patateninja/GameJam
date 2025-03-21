#pragma once
#include "SFML/Graphics.hpp"
#include "Window.h"
#include "Button.hpp"

namespace StateMenu
{
	void Init();
	void Update();
	void Display(Window& _window);
	void DeInit();
};
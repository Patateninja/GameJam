#include "Tools.h"
#include "SoundManager.h"
#include <iostream>
#include "tools.h"
#include "Window.h"
#include "View.h"
#include "Mouse.h"
#include "StateMachine.hpp"

int main()
{
	Sound::InitSoundManager();


	Window window("GameJam 2025" , sf::Vector2i(1920, 1080), false, true, false);

	View view(window);
	window.setView(&view);

	StateMachine::StateInit();

	while (window.isOpen())
	{
		updateDeltaTime();
		window.Update();

		Mouse::updateMousePosition(*window.getWindow());

		StateMachine::StateUpdate();

		StateMachine::StateDisplay(*window.getWindow());
	}
	Sound::SaveOption();


	return 42;
}
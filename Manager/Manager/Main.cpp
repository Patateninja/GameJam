#include "tools.h"
#include "SoundManager.h"
#include <iostream>
#include "tools.h"
#include "View.h"
#include "Mouse.h"
#include "StateMachine.hpp"


int main()
{
	int musicvolume = 50;
	int soundVolume = 50;
	Sound::InitSoundManager();
	Sound::getOption(musicvolume, soundVolume);
	float time = 0;


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

		window.Clear();

		StateMachine::StateDisplay(*window.getWindow());
	}

	return 42;
}
#include "Tools.h"
#include "SoundManager.h"
#include <iostream>

#include "Tools.h"
#include "Window.h"
#include "View.h"
#include "Mouse.h"
#include "StateMachine.hpp"

#include "Player.h"


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

	//Player
	Player::Init();

	StateMachine::StateInit();

	while (window.isOpen())
	{
		window.Update();
		Player::Update();
		Mouse::updateMousePosition(*window.getWindow());

		StateMachine::StateUpdate();

		StateMachine::StateDisplay(*window.getWindow());
	}

	return 42;
}
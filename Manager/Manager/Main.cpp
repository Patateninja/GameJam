#include "tools.h"
#include "SoundManager.h"
#include <iostream>

#include "tools.h"
#include "Window.h"
#include "View.h"
#include "Mouse.h"
#include "StateMachine.hpp"

#include "Player.h"
#include "Ultime.h"

#include "Surchauffe.h"


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

	Ultime::InitUltime();

	StateMachine::StateInit();

	while (window.isOpen())
	{
		window.Update();
		Player::Update();
		Ultime::UpdateUltime();
		Surchauffe::update();
		updateDeltaTime();
		Mouse::updateMousePosition(*window.getWindow());

		StateMachine::StateUpdate();

		window.Clear();

		Ultime::DisplayUltime(*window.getWindow());


		StateMachine::StateDisplay(*window.getWindow());
	}

	return 42;
}
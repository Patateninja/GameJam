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
#include "UI.h"


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

	Player::Init();

	Ultime::InitUltime();

	StateMachine::StateInit();

	UI::Init();

	while (window.isOpen())
	{
		updateDeltaTime();
		window.Update();
		Player::Update();
		Ultime::UpdateUltime();
		Mouse::updateMousePosition(*window.getWindow());

		StateMachine::StateUpdate();

		UI::Update();

		window.Clear();

		Ultime::DisplayUltime(*window.getWindow());

		UI::Display(*window.getWindow());

		StateMachine::StateDisplay(*window.getWindow());
	}

	return 42;
}
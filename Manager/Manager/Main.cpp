#include "Tools.h"
#include "SoundManager.h"
#include <iostream>

#include "Tools.h"
#include "Window.h"
#include "View.h"
#include "Mouse.h"
#include "StateMachine.hpp"

#include "Player.h"
#include "Ultime.h"


int main()
{
	Sound::InitSoundManager();


	Window window("GameJam 2025" , sf::Vector2i(1920, 1080), false, true, false);
	View view(window);
	window.setView(&view);

	//Player
	Player::Init();

	Ultime::InitUltime();

	StateMachine::StateInit();

	while (window.isOpen())
	{
		updateDeltaTime();
		window.Update();
		Player::Update();
		Ultime::UpdateUltime();
		Mouse::updateMousePosition(*window.getWindow());

		StateMachine::StateUpdate();

		window.Clear();

		Ultime::DisplayUltime(*window.getWindow());


		StateMachine::StateDisplay(*window.getWindow());
	}
	Sound::SaveOption();


	return 42;
}
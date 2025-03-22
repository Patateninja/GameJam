#include "Tools.h"
#include "SoundManager.h"
#include <iostream>
#include "Ultime.h"
#include "Tools.h"
#include "Window.h"
#include "View.h"
#include "Mouse.h"
#include "Player.h"
#include "StateMachine.hpp"

int main()
{
	std::vector<Obstacle*> obsList;

	Sound::InitSoundManager();
	Window window("GameJam 2025" , sf::Vector2i(1920, 1080), false, true, false);

	View view(window);
	window.setView(&view);

	StateMachine::StateInit();

	while (window.isOpen())
	{
		updateDeltaTime();
		window.Update();
		//Player::Update(obsList);
		Ultime::UpdateUltime();
		Mouse::updateMousePosition(*window.getWindow());

		StateMachine::StateUpdate();

		window.Clear();

		StateMachine::StateDisplay(*window.getWindow());
	}
	Sound::SaveOption();


	return 42;
}
#include "Tools.h"
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
	Sound::InitSoundManager();


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

		Mouse::updateMousePosition(*window.getWindow());

		StateMachine::StateUpdate();

		UI::Update(Player::GetHP());

		window.Clear();

		Ultime::DisplayUltime(*window.getWindow());

		UI::Display(*window.getWindow());

		StateMachine::StateDisplay(*window.getWindow());
	}
	Sound::SaveOption();


	return 42;
}
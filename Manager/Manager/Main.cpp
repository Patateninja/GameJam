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

	Window window("GameJam 2025" , sf::Vector2i(1920, 1080), true, true, false);

	View view(window);
	window.setView(&view);
	sf::Image ico;
	ico.loadFromFile("../Ressources/Textures/ICONE 128x128.png");
	window.getWindow()->setIcon(128, 128, ico.getPixelsPtr());




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
	Sound::SaveOption();


	return 42;
}
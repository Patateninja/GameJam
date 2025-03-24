 #include "Tools.hpp"
#include "SoundManager.hpp"
#include <iostream>
#include "tools.hpp"
#include "View.hpp"
#include "Mouse.hpp"
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

		std::cout << "Interact :: " << Keys::isInteractPressed + Keys::isInteractHeld << std::endl << "Up :: " << Keys::isUpPressed + Keys::isUpHeld << std::endl << "Down :: " << Keys::isDownPressed + Keys::isDownHeld << std::endl;

		StateMachine::StateDisplay(*window.getWindow());
	}
	Sound::SaveOption();


	return 42;
}
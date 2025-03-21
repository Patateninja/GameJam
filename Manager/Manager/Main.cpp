#include "tools.h"
#include "SoundManager.h"
#include <iostream>

#include "Window.h"
#include "View.h"
#include "Mouse.h"
#include "StateMachine.hpp"

#include "Player.h"
#include "Tir.h"


int main()
{
	int musicvolume = 50;
	int soundVolume = 50;
	Sound::InitSoundManager();
	Sound::getOption(musicvolume, soundVolume);
	float timer = 0;

	initTir();
    // To this line
	std::vector<Tir> tirs;

	Window window("GameJam 2025" , sf::Vector2i(1920, 1080), false, true, false);
	View view(window);
	window.setView(&view);

	//Player
	Player::Init();

	StateMachine::StateInit();

	while (window.isOpen())
	{
		updateDeltaTime();
		window.Update();
		Player::Update();
 		timer += getDeltaTime();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && timer > 0.2f)
		{
			timer = 0;
			tirs.push_back(Tir(90, sf::Vector2f(800,600), TypeTir::PETIT));
		}


		for (auto& tir : tirs)
		{
			tir.Update();
		}
		
		Mouse::updateMousePosition(*window.getWindow());

		StateMachine::StateUpdate();

		window.Clear();

		for (auto& tir : tirs)
		{
			tir.Display(*window.getWindow());
		}

		StateMachine::StateDisplay(*window.getWindow());
	}

	return 0;
}
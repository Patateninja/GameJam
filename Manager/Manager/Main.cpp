#include "SoundManager.h"
#include <iostream>
#include "tools.h"
#include "Window.h"
#include "View.h"
#include "Mouse.h"
#include "StateMachine.hpp"
#include "Player.h"
#include "Tir.h"

namespace
{
	std::list<Tir> TirList;
}

void addTir(float _angle, sf::Vector2f _pos,TypeTir _type)
{
	TirList.push_back(Tir(_angle, _pos, _type));
}

>>>>>>> Stashed changes


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

		//TODO deplacer dans le game
		time += getdeltaTime();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && time > 0.2f)
		{
			time = 0;
			addTir(90.f, sf::Vector2f(600.f, 600.f), PETIT);
		}

		for (auto& m : TirList)
		{
			m.UpdateTir();
			if (m.getTirVie() == 0)
			{
				m.~Tir();
			}
			else
			{
				m.DisplayTir(*window.getWindow());
			}
		}

		StateMachine::StateUpdate();

		StateMachine::StateDisplay(*window.getWindow());
	}

	return 42;
}
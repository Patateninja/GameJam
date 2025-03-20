#include "SoundManager.h"
#include <iostream>
#include "tools.h"
#include "StateMachine.hpp"

int main()
{
	int musicvolume = 50;
	int soundVolume = 50;
	Sound::InitSoundManager();
	Sound::getOption(musicvolume, soundVolume);
	float time = 0;
	sf::RenderWindow window(sf::VideoMode(800, 600), "GameJam 2025");
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		StateMachine::StateUpdate();
		time += getdeltaTime();
		Sound::updateMusic();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && time > 0.2f)
		{
			time = 0;
			Sound::PlaySound("bell");
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			Sound::PlaySound("cardSacrifice");
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			Sound::PlayMusic("Battle");
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			Sound::StopMusic("Battle");
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			Sound::setFutureMusic("Menu");
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
		{
			Sound::StopAllMusic();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
		{
			Sound::PlayMusic("Menu");
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && musicvolume < 100 && time > 0.1f)
		{
			time = 0;
			musicvolume += 1;
			Sound::changeMusicVolume(musicvolume);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && musicvolume > 0 && time > 0.1f)
		{
			time = 0;
			musicvolume -= 1;
			Sound::changeMusicVolume(musicvolume);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && time > 0.5f)
		{
			time = 0;
			Sound::SaveOption();
		}

		window.clear();
		StateMachine::StateDisplay();
		window.display();
	}

	return 0;
}
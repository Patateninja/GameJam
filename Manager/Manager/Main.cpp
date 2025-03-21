#include "tools.h"
#include "SoundManager.h"
#include <iostream>
<<<<<<< Updated upstream
#include "Player.h"
=======
#include "tools.h"
#include "Window.h"
#include "View.h"
#include "Mouse.h"
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

	//Player
	Player::Init();

	Window window("GameJam 2025" , sf::Vector2i(1920, 1080), true, true, false);
	View view(window);
	window.setView(&view);

	while (window.isOpen())
	{
		window.Update();
		Player::Update();
		Mouse::updateMousePosition(*window.getWindow());

<<<<<<< Updated upstream
=======
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

		pos = Mouse::getRelativeMousePos();
		shape.setPosition(pos);

		Sound::updateMusic();
		
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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && time > 0.1f)
		{
			sf::Vector2f pos = view.getCenter();
			pos.x += 10;
			view.setPosCenter(pos);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && time > 0.1f)
		{
			sf::Vector2f pos = view.getCenter();
			pos.x -= 10;
			view.setPosCenter(pos);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && time > 0.5f)
		{
			time = 0;
			Sound::SaveOption();
		}
>>>>>>> Stashed changes
		window.Clear();

		Player::Display(*window.getWindow());

		window.Display();
	}

	return 0;
}
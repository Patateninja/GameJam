#include "tools.h"
#include "SoundManager.h"
#include <iostream>
#include "tools.h"
#include "View.h"
#include "Cannon.h"
#include "Mouse.h"
#include "StateMachine.hpp"
#include "Player.h"


int main()
{
	int musicvolume = 50;
	int soundVolume = 50;
	Sound::InitSoundManager();
	Sound::getOption(musicvolume, soundVolume);
	float time = 0;

	Cannon gun = Cannon(BIGCANNON);
	Cannon gunSmol = Cannon(SMOLCANNON);
	initCannon();

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
		Mouse::updateMousePosition(*window.getWindow());

		StateMachine::StateUpdate();

#pragma region sound
		time += getDeltaTime();
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
#pragma endregion
		window.Clear();

		gun.Update();
		gun.Rotate(
			sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::K) -
			sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Semicolon)
		);
		

		gunSmol.Update();
		gunSmol.Rotate(
			sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D) -
			sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A)
		);

		gun.Display(*window.getWindow());
		gunSmol.Display(*window.getWindow());
		window.Draw(shape);

		window.Display();

		StateMachine::StateDisplay(*window.getWindow());

	}

	return 42;
}
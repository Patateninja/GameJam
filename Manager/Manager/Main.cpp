#include "SoundManager.h"
#include <iostream>
#include "tools.h"
#include "Window.h"
#include "View.h"
#include "Mouse.h"
#include "StateMachine.hpp"

int main()
{
	int musicvolume = 50;
	int soundVolume = 50;
	Sound::InitSoundManager();
	Sound::getOption(musicvolume, soundVolume);
	float time = 0;

	Window window("GameJam 2025" , sf::Vector2i(1920, 1080), true, true, false);
	View view(window);
	window.setView(&view);

	StateMachine::StateInit();

	sf::RectangleShape shape(sf::Vector2f(100, 100));
	shape.setFillColor(sf::Color::Red);
	sf::Vector2f pos = sf::Vector2f(0, 0);

	while (window.isOpen())
	{
		window.Update();
		Mouse::updateMousePosition(*window.getWindow());

		pos = Mouse::getRelativeMousePos();
		shape.setPosition(pos);
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
			Sound::changeMusicVolume(static_cast<float>(musicvolume));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && musicvolume > 0 && time > 0.1f)
		{
			time = 0;
			musicvolume -= 1;
			Sound::changeMusicVolume(static_cast<float>(musicvolume));
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
		
		window.Clear();

		window.Draw(shape);
		
		StateMachine::StateDisplay(window);

		window.Display();
	}

	return 0;
}
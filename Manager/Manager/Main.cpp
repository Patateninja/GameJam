#include "tools.h"
#include "SoundManager.h"
#include <iostream>
#include "Ennemy.h"

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

	Ennemy ennemy(sf::Vector2f(0, 0), EnemyClass::NORMAL);

	sf::RectangleShape shape(sf::Vector2f(100, 100));
	shape.setFillColor(sf::Color::Red);
	sf::Vector2f pos = sf::Vector2f(0, 0);

	while (window.isOpen())
	{
		updateDeltaTime();
		window.Update();
		Mouse::updateMousePosition(*window.getWindow());

		pos = Mouse::getRelativeMousePos();
		shape.setPosition(pos);

		time += getDeltaTime();
		Sound::updateMusic();

		ennemy.update();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && time > 0.5f)
		{
			time = 0;
			Sound::SaveOption();
		}
		window.Clear();

		window.Draw(shape);

		ennemy.display(*window.getWindow());

		window.Display();
	}

	return 0;
}
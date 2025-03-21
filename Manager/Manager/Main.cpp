#include "tools.h"
#include "SoundManager.h"
#include <iostream>
#include "Player.h"

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

		window.Clear();

		Player::Display(*window.getWindow());

		window.Display();
	}

	return 0;
}
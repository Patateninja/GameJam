#include "StateSettings.hpp"
#include "SoundManager.h"

namespace StateSettings
{
	sf::Sprite settingsMenuBackground;
	sf::Sprite caret1Sprite;
	sf::Sprite caret2Sprite;
	sf::Sprite backArrowSprite;
	sf::Texture settingsTexture;
	sf::Texture hoverTexture;

	int selIndex = 3;
	int musicVolume;
	int soundVolume;

	float caretMIN = 694.f;
	float caretMAX = 1415.f;
}

void StateSettings::Init()
{
	settingsTexture.loadFromFile("../Ressources/Textures/settings.png");
	hoverTexture.loadFromFile("../Ressources/Textures/main_menu_hover.png");
	caret1Sprite.setTexture(hoverTexture);
	caret1Sprite.setPosition(caretMIN, 350.f);
	caret2Sprite.setTexture(hoverTexture);
	caret2Sprite.setPosition(caretMIN, 644.f);
	backArrowSprite.setTexture(hoverTexture);
	backArrowSprite.setPosition(662.f, 912.f);
	settingsMenuBackground.setTexture(settingsTexture);
}

void StateSettings::Update()
{
	static float timer = 0.f;
	timer += getDeltaTime();
	Sound::getOption(musicVolume, soundVolume);
	caret1Sprite.setTextureRect(sf::IntRect(1146, 41, 25, 112));
	caret2Sprite.setTextureRect(sf::IntRect(1146, 41, 25, 112));
	backArrowSprite.setTextureRect(sf::IntRect(0, 0, 0, 0));

	switch (selIndex)
	{
	case 1: //SFX
		caret1Sprite.setTextureRect(sf::IntRect(1172, 41, 25, 112));
		break;
	case 2: //MUS
		caret2Sprite.setTextureRect(sf::IntRect(1172, 41, 25, 112));
		break;
	case 3: //QUIT
		backArrowSprite.setTextureRect(sf::IntRect(1197, 41, 599, 112));
		break;
	}
	if (timer > 0.25f)
	{
		switch (selIndex)
		{
		case 1: //SFX
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { Sound::changeSoundVolume(std::min(soundVolume+1, 100)); };
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  { Sound::changeSoundVolume(std::max(soundVolume-1, 0)); };
			break;
		case 2: //MUS
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { Sound::changeMusicVolume(std::min(musicVolume+1, 100)); };
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  { Sound::changeMusicVolume(std::max(musicVolume-1, 0)); };
			break;
		case 3: //QUIT
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) 
			{
				StateMachine::toggleIsPaused();
				timer = 0.f;
			}
			break;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			selIndex = std::min(selIndex+1, 3);
			timer = 0.f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			selIndex = std::max(selIndex-1, 1);
			timer = 0.f;
		}
	}
}

void StateSettings::Display(sf::RenderWindow& _window)
{
	caret1Sprite.setPosition(caretMIN + ((soundVolume / 100.f) * (caretMAX - caretMIN)), caret1Sprite.getPosition().y);
	caret2Sprite.setPosition(caretMIN + ((musicVolume / 100.f) * (caretMAX - caretMIN)), caret2Sprite.getPosition().y);
	_window.draw(settingsMenuBackground);
	_window.draw(caret1Sprite);
	_window.draw(caret2Sprite);
	_window.draw(backArrowSprite);
}

void StateSettings::DeInit()
{
}
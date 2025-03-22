#include "StateMenu.hpp"
#include "StateMachine.hpp"
#include <iostream>

namespace
{
	sf::Sprite spriteMenu;
	sf::Sprite spriteMenuHover;
	sf::Texture textureMenu;
	sf::Texture textureMenuHover;

	

	ActualMenu MainMenu = ActualMenu();
}

void StateMenu::Init()
{
	Sound::StopMusic("MusicGame");
	textureMenu.loadFromFile("../Ressources/Textures/main_menu.png");
	textureMenuHover.loadFromFile("../Ressources/Textures/main_menu_hover.png");
	
	spriteMenu.setTexture(textureMenu);
	spriteMenuHover.setTexture(textureMenuHover);

	//spriteMenuHover.setOrigin(spriteMenuHover.getGlobalBounds().width / 2, spriteMenuHover.getGlobalBounds().height / 2);

	MainMenu = ActualMenu();
	MainMenu.ResetClock();
	Sound::PlayMusic("MusicMenu");
}

void StateMenu::Update()
{
	if (MainMenu.GetList().size() == 0)
	{
		MainMenu.Add(new Button(TO_GAME, sf::Vector2f(150.f, 75.f),  MainMenu));
		MainMenu.Add(new Button(TO_SETTINGS, sf::Vector2f(150.f, 275.f), MainMenu));
		MainMenu.Add(new Button(TO_QUIT, sf::Vector2f(150.f, 475.f), MainMenu));
	}

	switch (MainMenu.GetSelectedButton())
	{
	default:
		break;
	case 0:
		spriteMenuHover.setPosition(682, 509);
		spriteMenuHover.setTextureRect(sf::IntRect(0, 0, 520, 152 ));
		break;
	case 1:
		spriteMenuHover.setPosition(713, 723);
		spriteMenuHover.setTextureRect(sf::IntRect(520, 0, 467, 150));
		break;
	case 2:
		spriteMenuHover.setPosition(849, 871);
		spriteMenuHover.setTextureRect(sf::IntRect(987, 0, 159, 150));
		break;
	}

	switch (MainMenu.Update())
	{
		case TO_SETTINGS :
			StateMachine::toggleIsPaused();
			break;
		case TO_GAME :
			StateMachine::ChangeState(GAME);
			break;
		case TO_QUIT :
			StateMachine::ChangeState(QUIT);
			break;
	}


}

void StateMenu::Display(sf::RenderWindow& _window)
{
	_window.draw(spriteMenu);
	_window.draw(spriteMenuHover);
	MainMenu.Display(_window);

}

void StateMenu::DeInit()
{
	//DeInit
}
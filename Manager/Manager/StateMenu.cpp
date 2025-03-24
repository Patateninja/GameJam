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
	Sound::StopAllMusic();
	Sound::PlayMusic("MusicMenu");
	textureMenu.loadFromFile("../Ressources/Textures/main_menu.png");
	textureMenuHover.loadFromFile("../Ressources/Textures/main_menu_hover.png");
	
	spriteMenu.setTexture(textureMenu);
	spriteMenuHover.setTexture(textureMenuHover);

	//spriteMenuHover.setOrigin(spriteMenuHover.getGlobalBounds().width / 2, spriteMenuHover.getGlobalBounds().height / 2);

	MainMenu = ActualMenu();
	MainMenu.ResetClock();
}

void StateMenu::Update()
{
	if (MainMenu.GetList().size() == 0)
	{
		MainMenu.Add(new Button(TO_TUTORIAL, sf::Vector2f(-500.f, 75.f), MainMenu));
		MainMenu.Add(new Button(TO_SETTINGS, sf::Vector2f(-500.f, 275.f), MainMenu));
		MainMenu.Add(new Button(TO_QUIT, sf::Vector2f(-500.f, 475.f), MainMenu));
		MainMenu.Add(new Button(TO_CREDITS, sf::Vector2f(-500.f, 675.f), MainMenu));
	}

	switch (MainMenu.GetSelectedButton())
	{
	default:
		break;
	case 0:
		spriteMenuHover.setPosition(682, 475);
		spriteMenuHover.setTextureRect(sf::IntRect(0, 0, 520, 185 ));
		break;
	case 1:
		spriteMenuHover.setPosition(713, 688);
		spriteMenuHover.setTextureRect(sf::IntRect(520, 0, 467, 185));
		break;
	case 2:
		spriteMenuHover.setPosition(849, 836);
		spriteMenuHover.setTextureRect(sf::IntRect(987, 0, 159, 185));
		break;
	case 3:
		spriteMenuHover.setPosition(51, 835);
		spriteMenuHover.setTextureRect(sf::IntRect(2094, 0, 159, 185));
		break;
	}

	switch (MainMenu.Update())
	{
	case TO_SETTINGS:
		StateMachine::toggleIsPaused();
		break;
	case TO_TUTORIAL:
		StateMachine::ChangeState(TUTO);
		break;
	case TO_GAME:
		StateMachine::ChangeState(GAME);
		break;
	case TO_CREDITS:
		StateMachine::ChangeState(CREDITS);
		break;
	case TO_QUIT:
		StateMachine::ChangeState(QUIT);
		break;
	case TO_GAMEOVER:
		StateMachine::ChangeState(GAMEOVER);
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
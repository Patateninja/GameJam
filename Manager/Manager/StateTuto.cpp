#include "StateTuto.h"
#include "StateMachine.hpp"

namespace StateTuto
{
	sf::Sprite tutoFond;
	sf::Texture tutoFondTexture;
	sf::Vector2f tutoFondPos;
}

void StateTuto::Init()
{
	tutoFondTexture.loadFromFile("../Ressources/Textures/tuto.png");
	tutoFond.setTexture(tutoFondTexture);
	tutoFond.setPosition(tutoFondPos);
}

void StateTuto::Update()
{
	// si touche enter appuyée, retour au menu
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		StateMachine::ChangeState(GAME);
	}
}

void StateTuto::Display(sf::RenderWindow& _window)
{
	_window.draw(tutoFond);
}

void StateTuto::DeInit()
{
}
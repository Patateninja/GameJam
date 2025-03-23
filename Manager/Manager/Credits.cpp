#include "Credits.h"



namespace StateCredits
{
	sf::Sprite creditsFond;
	sf::Texture creditsFondTexture;
	sf::Vector2f creditsFondPos;
}

void StateCredits::InitCredits()
{
	creditsFondTexture.loadFromFile("../Ressources/Textures/Encul�DeTesMortEnAttendantLeVraiSprite.png");
	creditsFond.setTexture(creditsFondTexture);
	creditsFond.setPosition(creditsFondPos);
}

void StateCredits::UpdateCredits()
{

}

void StateCredits::DisplayCredits(sf::RenderWindow& _window)
{
	_window.draw(creditsFond);
}

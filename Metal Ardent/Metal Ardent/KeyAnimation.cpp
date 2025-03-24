#include "KeyAnimation.hpp"

namespace KeyAnim
{
	sf::IntRect rectSerrure(0, 0, 100, 100);
	sf::IntRect rectKeyAnim1(0, 0, 100, 100);
	sf::IntRect rectKeyAnim2(0, 0, 100, 100);

	sf::Sprite spriteSerrureBackground;
	sf::Sprite spriteKey1;
	sf::Sprite spriteKey2;

	sf::Texture textureSerrureBackground;
	sf::Texture textureKey;

	sf::Vector2f positionKey1(0,0);
	sf::Vector2f positionKey2(0,0);
}

void KeyAnim::Init()
{
	textureSerrureBackground.loadFromFile("../Ressources/Textures/serrure.png");
	textureKey.loadFromFile("../Ressources/Textures/clef.png");

	spriteSerrureBackground.setTexture(textureSerrureBackground);
	spriteKey1.setTexture(textureKey);
	spriteKey2.setTexture(textureKey);
}

void KeyAnim::Update()
{

}

void KeyAnim::Display()
{

}
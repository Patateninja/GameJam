#include "Map.h"

namespace Map
{
	sf::Sprite mapSprite;
	sf::Texture mapTexture;
	int tileX;
	int tileY;
}

void Map::InitMap()
{
	mapTexture.loadFromFile("../Ressources/Textures/FOND.png");
	mapSprite.setTexture(mapTexture);
	mapSprite.setOrigin(mapSprite.getGlobalBounds().width / 2, mapSprite.getGlobalBounds().height / 2);
}

void Map::UpdateMap()
{
	sf::Vector2f playerPos;
	tileX = playerPos.x / 1920;
	tileY = playerPos.y / 1080;
	tileX * 1920;
	tileY * 1080;
}

void Map::DisplayMap(sf::RenderWindow& _window)
{
	mapSprite.setPosition((float)tileX - 1920, (float)tileY - 1080);
	_window.draw(mapSprite);

	mapSprite.setPosition((float)tileX - 1920, (float)tileY);
	_window.draw(mapSprite);

	mapSprite.setPosition((float)tileX - 1920, (float)tileY + 1080);
	_window.draw(mapSprite);

	mapSprite.setPosition((float)tileX, (float)tileY - 1080);
	_window.draw(mapSprite);

	mapSprite.setPosition((float)tileX, (float)tileY);
	_window.draw(mapSprite);

	mapSprite.setPosition((float)tileX, (float)tileY + 1080);
	_window.draw(mapSprite);

	mapSprite.setPosition((float)tileX + 1920, (float)tileY - 1080);
	_window.draw(mapSprite);

	mapSprite.setPosition((float)tileX + 1920, (float)tileY);
	_window.draw(mapSprite);

	mapSprite.setPosition((float)tileX + 1920, (float)tileY + 1080);
	_window.draw(mapSprite);

}

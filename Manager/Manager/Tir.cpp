#include "Tir.h"

namespace
{
	sf::IntRect ptit = { 0, 0, 0, 0 };
	sf::IntRect gros = { 0, 0, 0, 0 };
	sf::Sprite spriteTir;
	sf::Texture textureTir;
	TypeTir oldType;
}

void InitTir()
{
	textureTir.loadFromFile("../Ressources/Textures/Tir.png");
	spriteTir.setTexture(textureTir);
	spriteTir.setTextureRect(ptit);
	oldType = PETIT;
}

Tir::Tir(float _angleTir, sf::Vector2f _posTir, TypeTir _type)
{
	m_vie = 1;
	m_type = _type;
	m_posTir = _posTir;
	m_angleTir = _angleTir;
	if (_type == PETIT)
	{
		m_velocityTir = sf::Vector2f(200.f, 200.f);
	}
	else
	{
		m_velocityTir = sf::Vector2f(400.f, 400.f);
	}
}

void Tir::UpdateTir()
{


	m_posTir += m_velocityTir * getdeltaTime();
}

void Tir::DisplayTir(sf::RenderWindow& _window)
{
	if (m_type == PETIT && oldType != PETIT)
	{
		spriteTir.setTextureRect(ptit);
	}
	else if (m_type == GROS && oldType != GROS)
	{
		spriteTir.setTextureRect(gros);
	}
	spriteTir.setPosition(m_posTir);
	spriteTir.setRotation(m_angleTir);
	_window.draw(spriteTir);
}

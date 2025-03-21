#include "Tir.h"

namespace
{
	sf::IntRect ptit = { 0, 0, 0, 0 };
	sf::IntRect gros = { 0, 0, 0, 0 };
	sf::Sprite spriteTir;
	sf::Texture textureTir;
	TypeTir oldType;

	std::list<Tir> TirList;
}

void addTir(float _angle, sf::Vector2f _pos, TypeTir _type)
{
	TirList.push_back(Tir(_angle, _pos, _type));
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		addTir(90.f, sf::Vector2f(600.f, 600.f), PETIT);
	}

	for (auto& m : TirList)
	{
		m.UpdateTir();
		if (m.getTirVie() == 0)
		{
			m.~Tir();
		}
	}
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

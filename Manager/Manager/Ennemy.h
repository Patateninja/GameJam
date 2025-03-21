#pragma once
#include "SFML/Graphics.hpp"

typedef enum EnemyClass
{
	NORMAL,
	TANK,
	SPEEDSTER,
};

class Ennemy
{
	private :
		sf::Vector2f m_pos = sf::Vector2f(0.f,0.f);
		EnemyClass m_Class;
		int m_HP;
		
};
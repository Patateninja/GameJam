#include "Ennemy.h"

Ennemy::Ennemy(sf::Vector2f pos, EnemyClass type)
{
	m_pos = pos;
	m_class = type;
	m_pv = 100;
	m_velocity = sf::Vector2f(0, 0);
	angle = 0;
}

Ennemy::~Ennemy()
{
}

void Ennemy::update()
{
	m_pos += m_velocity;
}

void Ennemy::display(sf::RenderWindow& window)
{

}

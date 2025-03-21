#include "Ennemy.hpp"
#include "Graph.hpp"

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

void Ennemy::followPath()
{
	if (!this->path.empty())
	{
		this->currentNode = this->path.back();
		this->x = this->currentNode->getX();
		this->y = this->currentNode->getY();
		if (this->currentNode != this->path.front())
		{
			this->path.pop_back();
		}
	}
}
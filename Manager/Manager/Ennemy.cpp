#include "Ennemy.h"
#include "Player.h"

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

//faire exploser l'ennemi

void Ennemy::explode(std::list<Ennemy> listEnemy)
{
	for (std::list<Ennemy>::iterator it = listEnemy.begin(); it != listEnemy.end(); ++it)
	{
		//si l'ennemi est a portee avec la position du Player
		if (it->getPos().x < Player::GetSpritePlayer().getPosition().x + 50 && it->getPos().x > Player::GetSpritePlayer().getPosition().x - 50 && it->getPos().y < Player::GetSpritePlayer().getPosition().y + 50 && it->getPos().y > m_pos.y - 50)
		{
			//faire exploser
			// TODO : faire Animation d'explosion
			it->setPv(0);
		}
	}

}

void Ennemy::display(sf::RenderWindow& window)
{

}

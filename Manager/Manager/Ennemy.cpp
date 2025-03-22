#include "Ennemy.hpp"

#include <iostream>

Enemy::Enemy(sf::Vector2f pos, EnemyClass type)
{
	this->m_pos = pos;
	this->m_class = type;
	this->m_pv = 100;
	this->m_speed = 5.f;
	this->m_velocity = sf::Vector2f(0, 0);
	this->angle = 0;
}

Enemy::~Enemy()
{

}

void Enemy::update(std::vector<Obstacle*> _obstacleList)
{
	sf::Vector2f Current_Pos = this->m_pos;
	auto ObstaclesInRange = _obstacleList | std::views::filter([Current_Pos] (Obstacle* currentObstacle) { return Math::distance(currentObstacle->m_circle.getGlobalBounds().getPosition(), Current_Pos) <= 500;});
	
	float closestDistance = -1;
	Obstacle* ClosestObstacle  = nullptr;

	for (Obstacle* n : ObstaclesInRange)
	{
		if(Math::distance(n->m_circle.getGlobalBounds().getPosition(), Current_Pos) <= closestDistance || closestDistance == -1)
		{
			closestDistance = Math::distance(n->m_circle.getGlobalBounds().getPosition(), Current_Pos);
			ClosestObstacle = n;
		}
	}

	this->Seek(Mouse::getRelativeMousePos(), ClosestObstacle);
	this->m_pos += m_velocity;
}

void Enemy::display(sf::RenderWindow& window)
{
	sf::RectangleShape rect(sf::Vector2f(40.f, 40.f));
	rect.setOrigin(20.f, 20.f);
	rect.setPosition(this->m_pos);
	window.draw(rect);

	sf::VertexArray vect(sf::Lines, 2);
	vect[0].position = this->m_pos;
	vect[0].color = sf::Color::Red;
	vect[1].position = this->m_pos + this->m_velocity * Math::magnitude(this->m_velocity);
	vect[1].color = sf::Color::Red;
	window.draw(vect);
}

void Enemy::Seek(sf::Vector2f _target, Obstacle* _closestObstacle)
{
	float threshold = 120.f;

	sf::Vector2f avoidance(0.f, 0.f);

	if (_closestObstacle != nullptr)
	{
		sf::Vector2f dist = _closestObstacle->m_circle.getPosition() - this->m_pos;
		float len = Math::magnitude(dist);
		if (len < threshold)
		{
			avoidance = Math::normalize(dist) * (threshold - len);
		}
	}

	sf::Vector2f ToTarget = _target - this->m_pos;
	float ramped_speed = this->m_speed * (Math::distance(_target, this->m_pos) / 50.f);
	float speed = (this->m_speed > ramped_speed ? ramped_speed : this->m_speed);
	sf::Vector2f NormalizedToTarget = Math::normalize(ToTarget) * speed;
	this->m_velocity += NormalizedToTarget - this->m_velocity - avoidance;
}
#include "Ennemy.hpp"

#include <iostream>

void CreateObstacle(sf::Vector2f _pos, ObstacleType _type, std::vector<Obstacle*>& _list)
{
	_list.push_back(new Obstacle(_pos, _type));
}

Enemy::Enemy(sf::Vector2f pos, EnemyClass type)
{
	this->m_pos = pos;
	this->m_class = type;
	this->m_hp = 100;
	this->m_speed = 5.f;
	this->m_velocity = sf::Vector2f(0, 0);
	this->angle = 0;
}

Enemy::~Enemy()
{

}

bool Enemy::update(std::vector<Obstacle*> _obstacleList, std::list<Enemy*>& _list)
{
	sf::Vector2f Current_Pos = this->m_pos;
	auto ObstaclesInRange = _obstacleList | std::views::filter([Current_Pos] (Obstacle* currentObstacle) { return Math::distance(currentObstacle->GetPosition(), Current_Pos) <= 500;});
	
	float closestDistance = -1;
	Obstacle* ClosestObstacle  = nullptr;

	for (Obstacle* n : ObstaclesInRange)
	{
		if(Math::distance(n->GetPosition(), Current_Pos) <= closestDistance || closestDistance == -1)
		{
			closestDistance = Math::distance(n->GetPosition(), Current_Pos);
			ClosestObstacle = n;
		}
	}

	this->Seek(Mouse::getRelativeMousePos(), ClosestObstacle);
	this->m_pos += m_velocity;

	this->m_hp -= (getDeltaTime() * 5.f);

	if (this->m_hp <= 0)
	{
		this->Die(_list);
		return false;
	}
	return true;
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
	

	sf::Vector2f avoidance(0.f, 0.f);

	if (_closestObstacle != nullptr)
	{

		float threshold = _closestObstacle->thresholdAvoidance;

		sf::Vector2f dist = _closestObstacle->GetPosition() - this->m_pos;
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

void Enemy::Die(std::list<Enemy*>& _list)
{
	for (std::list<Enemy*>::iterator it = _list.begin(); it != _list.end();)
	{
		if (*it == this)
		{
			delete this;
			it = _list.erase(it);
		}
		else
		{
			++it;
		}
	}
}

void Spawn(sf::Vector2f _pos, EnemyClass _type, std::list<Enemy*>& _list)
{
	_list.push_back(new Enemy(_pos, _type));
}
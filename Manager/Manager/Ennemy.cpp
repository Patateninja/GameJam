#include "Ennemy.hpp"
#include "Player.h"
#include "UI.h"
#include <iostream>

void CreateObstacle(sf::Vector2f _pos, ObstacleType _type, std::vector<Obstacle*>& _list)
{
	_list.push_back(new Obstacle(_pos, _type));
}

Enemy::Enemy(sf::Vector2f pos, EnemyClass type)
{
	this->m_Rect = sf::RectangleShape(sf::Vector2f(30.f, 30.f));
	//this->m_Rect.setTexture(&this->m_Texture);
	this->m_Rect.setOrigin(sf::Vector2f(15.f, 15.f));
	this->m_pos = pos;
	this->m_class = type;
	this->m_hp = 200;
	this->m_velocity = sf::Vector2f(0, 0);
	this->angle = 0;

	switch(type)
	{
		case NORMAL :
			this->m_Texture.loadFromFile("..\\Ressources\\Textures\\vers de sable.png");
			this->m_hp = 100;
			this->m_speed = 0.5f;
			break;
		case TANK :
			this->m_Texture.loadFromFile("..\\Ressources\\Textures\\araigner_L_1815_H_355.png");
			this->m_hp = 250;
			this->m_speed = 0.3f;
			break;
		case SPEEDSTER :
			this->m_Texture.loadFromFile("..\\Ressources\\Textures\\monstre_vol_L155_H171.png");
			this->m_hp = 50;
			this->m_speed = 1.5f;
			break;
		case KAMIKAZE :
			this->m_Texture.loadFromFile("..\\Ressources\\Textures\\kamikaze_L_525_H_198.png");
			this->m_hp = 30;
			this->m_speed = 1.f;
			break;
		default :
			this->m_hp = 0;
			this->m_speed = 0.f;
			break;
	}

	this->m_Rect.setTexture(&this->m_Texture);
}

Enemy::~Enemy()
{

}

bool Enemy::Update(std::vector<Obstacle*> _obstacleList, std::list<Enemy*>& _Elist)
{
	//Obstacle Managerment
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

	//Avoid
	this->Seek(Player::GetPlayerPosition(), ClosestObstacle);
	
	//Movment
	this->m_pos += m_velocity;
	this->m_Rect.setPosition(this->m_pos);

	this->CheckForHit();

	if (this->m_hp <= 0)
	{
		this->Die(_Elist);
		return false;
	}
	return true;
}

void Enemy::Display(sf::RenderWindow& window)
{
	window.draw(this->m_Rect);
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

void Enemy::CheckForHit()
{
	for (Tir& tir : getTirList())
	{
		if (this->m_Rect.getGlobalBounds().contains(tir.GetPos()))
		{
			if (tir.GetType() == PETIT)
			{
				this->TakeDamage(5.f);
			}
			else
			{
				this->TakeDamage(125.f);
			}

			tir.Kill();
		}
	}
}

void Enemy::TakeDamage(int _damage)
{
	this->m_hp -= _damage;
}

void Enemy::Die(std::list<Enemy*>& _list)
{
	for (std::list<Enemy*>::iterator it = _list.begin(); it != _list.end();)
	{
		if (*it == this)
		{
			if ((*it)->getClass() == KAMIKAZE) Explode(_list);
			UI::KillEnemy();
			delete this;
			it = _list.erase(it);
		}
		else
		{
			++it;
		}
	}
}

void Enemy::Explode(std::list<Enemy*>& _list)
{
	for (std::list<Enemy*>::iterator it = _list.begin(); it != _list.end();)
	{
		if (Math::pointCircle(m_pos, (*it)->getPos(), 20.f)) // for each Enemy in a 20px radius
		{
			(*it)->setPv((*it)->getPv() - 100);
		}
		
		++it;
	}
	if (Math::pointCircle(m_pos, Player::GetPlayerPosition(), 80.f))
	{
		Player::Hurt(1);
	}
}

void Spawn(sf::Vector2f _pos, EnemyClass _type, std::list<Enemy*>& _list)
{
	_list.push_back(new Enemy(_pos, _type));
}
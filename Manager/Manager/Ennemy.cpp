#include "Ennemy.hpp"
#include "Player.h"
#include "UI.h"
#include <iostream>

Enemy::Enemy(sf::Vector2f pos, EnemyClass type)
{
	this->m_Rect = sf::RectangleShape(sf::Vector2f(60.f, 60.f));
	this->m_Rect.setOrigin(sf::Vector2f(30.f, 30.f));
	this->m_pos = pos;
	this->m_class = type;
	this->m_hp = 200;
	this->m_velocity = sf::Vector2f(0, 0);
	this->angle = 0;

	switch(type)
	{
		case NORMAL :
			this->m_Texture.loadFromFile("..\\Ressources\\Textures\\worm331.png");
			this->m_Rect.setTexture(&this->m_Texture);
			this->m_Rect.setTextureRect(sf::IntRect(0, 0, 331, 186));
			this->m_animFrameNb = 3;
			this->m_hp = 100;
			this->m_speed = 0.5f;
			break;
		case TANK :
			this->m_Texture.loadFromFile("..\\Ressources\\Textures\\spider355.png");
			this->m_Rect.setTexture(&this->m_Texture);
			this->m_Rect.setTextureRect(sf::IntRect(0, 0, 363, 355));
			this->m_animFrameNb = 5;
			this->m_hp = 250;
			this->m_speed = 0.3f;
			break;
		case SPEEDSTER :
			this->m_Texture.loadFromFile("..\\Ressources\\Textures\\fly155.png");
			this->m_Rect.setTexture(&this->m_Texture);
			this->m_Rect.setTextureRect(sf::IntRect(0, 0, 155, 171));
			this->m_animFrameNb = 3;
			this->m_hp = 50;
			this->m_speed = 1.5f;
			break;
		case KAMIKAZE :
			this->m_Texture.loadFromFile("..\\Ressources\\Textures\\kamikaze175.png");
			this->m_Rect.setTexture(&this->m_Texture);
			this->m_Rect.setTextureRect(sf::IntRect(0, 0, 175, 198));
			this->m_animFrameNb = 3;
			this->m_hp = 30;
			this->m_speed = 1.f;
			break;
		default :
			this->m_hp = 0;
			this->m_speed = 0.f;
			break;
	}

}

Enemy::~Enemy()
{

}

bool Enemy::Update(std::list<Enemy*>& _Elist)
{
	//Avoid
	this->Seek(Player::GetPlayerPosition());
	
	//Movment
	this->m_pos += m_velocity;
	this->m_Rect.setPosition(this->m_pos);

	Animate();

	this->CheckForHit();

	if (this->m_hp <= 0)
	{
		this->Die(_Elist);
		return false;
	}
	return true;
}

void Enemy::Animate()
{
	this->m_animTimer += getDeltaTime();
	sf::Vector2f plrDistance = Player::GetPlayerPosition() - this->m_pos;
	if (this->m_class == NORMAL || this->m_class == TANK) this->m_Rect.setRotation(180.f + RAD2DEG * std::atan2f(plrDistance.y, plrDistance.x));

	if (this->m_animTimer > 0.1f)
	{
		this->m_animTimer = 0.f;
		this->m_frameX = (this->m_frameX + 1) % this->m_animFrameNb;
		sf::IntRect oldRect = this->m_Rect.getTextureRect();

		this->m_Rect.setTextureRect(sf::IntRect(oldRect.width * this->m_frameX, oldRect.top, oldRect.width, oldRect.height));
	}
}

void Enemy::Display(sf::RenderWindow& window)
{
	window.draw(this->m_Rect);
}

void Enemy::Seek(sf::Vector2f _target)
{
	sf::Vector2f ToTarget = _target - this->m_pos;
	float ramped_speed = this->m_speed * (Math::distance(_target, this->m_pos) / 50.f);
	float speed = (this->m_speed > ramped_speed ? ramped_speed : this->m_speed);
	sf::Vector2f NormalizedToTarget = Math::normalize(ToTarget) * speed;
	this->m_velocity += NormalizedToTarget - this->m_velocity;
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
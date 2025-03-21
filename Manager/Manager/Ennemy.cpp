#include "Ennemy.hpp"

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

void Enemy::update()
{
	this->Seek(Mouse::getRelativeMousePos());
	this->m_pos += m_velocity;
}

void Enemy::display(sf::RenderWindow& window)
{
	sf::RectangleShape rect(sf::Vector2f(40.f, 40.f));
	rect.setOrigin(20.f, 20.f);
	rect.setPosition(this->m_pos);
	window.draw(rect);
}

void Enemy::Seek(sf::Vector2f _target)
{
	sf::Vector2f ToTarget = _target - this->m_pos;
	float ramped_speed = this->m_speed * (Math::distance(_target, this->m_pos) / 50.f);
	float speed = (this->m_speed > ramped_speed ? ramped_speed : this->m_speed);
	sf::Vector2f NormalizedToTarget = Math::normalize(ToTarget) * speed;
	this->m_velocity += NormalizedToTarget - this->m_velocity;
}
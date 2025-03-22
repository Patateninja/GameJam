#pragma once
#include "tools.h"

enum TypeTir 
{
	PETIT,
	GROS
};
 
class Tir 
{
public:
	Tir(float angle, sf::Vector2f position, TypeTir type);
	~Tir() {};
	void Update();
	void Display(sf::RenderWindow& window);
	bool isAlive() const;
	void destroyIfDead();

private:
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
	float m_angle;
	float lifeTimer;
	float animTimer;
	int frameX = 0; // MAX 13
	TypeTir m_type;
	bool m_alive;
};

void initTir();
std::list<Tir>& getTirList();
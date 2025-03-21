#pragma once
#include "tools.h"

typedef enum EnemyClass
{
	NORMAL,
	TANK,
	SPEEDSTER,
};

class Ennemy
{
private:
	sf::Vector2f m_pos;
	EnemyClass m_class;
	int m_pv;
	sf::Vector2f m_velocity;
	float angle;

public:
	Ennemy(sf::Vector2f pos, EnemyClass type);
	~Ennemy();

	void update();
	bool IsColliding(const sf::IntRect rect);
	void display(sf::RenderWindow& window);

	//getters
	inline sf::Vector2f getPos() { return m_pos; };
	inline EnemyClass getClass() { return m_class; };
	inline sf::Vector2f getVelocity() { return m_velocity; };
	inline float getAngle() { return angle; };
	inline int getPv() { return m_pv; };
	
	//setters
	inline void setPv(int _pv) { m_pv = _pv; };
	inline void setPos(sf::Vector2f _pos) { m_pos = _pos; };
	inline void setVelocity(sf::Vector2f _velocity) { m_velocity = _velocity; };
	inline void setAngle(float _angle) { angle = _angle; };
};
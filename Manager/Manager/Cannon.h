#pragma once
#include "tools.h"

enum enumBienGuez {
	BIGCANNON,
	SMOLCANNON
};

class Cannon
{
private:
	sf::Vector2f pos;

	float rot_MIN;
	float rot_MAX;
	float rotSpeed;
	float rotDeg;

	float shootCooldown;
	// add bullet

public:

	Cannon();
	Cannon(sf::Vector2f _pos, float _rotSpeed, float _rotDeg);
	Cannon(enumBienGuez _type);
	~Cannon();

	inline float getShootCooldown();
	inline float getRotDegrees();
	inline void setShootCooldown(const float _shootCooldown);
	inline void setRotDegrees(const float _rotDegrees);

	void Update();
	void Rotate(int _dir); // RIGHT - LEFT (1 for right, -1 for left)
	void Shoot();
	void Display(sf::RenderWindow& _window);
};

void initCannon();

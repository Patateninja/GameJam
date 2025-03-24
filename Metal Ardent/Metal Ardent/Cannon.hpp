#pragma once
#include "tools.hpp"
#include "Tir.hpp"

enum enumBienGuez {
	BIGCANNON,
	SMOLCANNON1,
	SMOLCANNON2
};

class Cannon
{
private:
	enumBienGuez type;
	sf::Vector2f basePos;
	sf::Vector2f muzzleLPos;
	sf::Vector2f muzzleRPos;
	sf::Vector2f origin;
	float rot_MIN;
	float rot_MAX;
	float rotSpeed;
	float rotDeg;

	float shootTimer = 0.f;
	float shootCooldown;
	int damage;
	// add bullet

public:

	Cannon();
	Cannon(enumBienGuez _type, float _shootCooldown, float _rotSpeed, float _rotDeg);
	Cannon(enumBienGuez _type);
	~Cannon();

	inline float getShootCooldown();
	inline float getRotDegrees();
	inline void setShootCooldown(const float _shootCooldown);
	inline void setRotDegrees(const float _rotDegrees);

	void Update();
	void Rotate(int _dir); // RIGHT - LEFT (1 for right, -1 for left)
	void Shoot(TypeTir _type);
	void Display(sf::RenderWindow& _window);
};

void initCannon();

#include <iostream>

#include "Cannon.h"

namespace holder {
	sf::Sprite sprite;
	sf::Texture texture;
}

void initCannon()
{
	holder::texture.loadFromFile("../Ressources/Textures/headcannon.png");
}

Cannon::Cannon()
{
	Cannon::pos = { 100.f, 100.f };
	Cannon::shootCooldown = 1.f;
	Cannon::rotSpeed = 80.f;
	Cannon::rotDeg = 180.f;
	Cannon::rot_MIN = Cannon::rotDeg - 40.f;
	Cannon::rot_MAX = Cannon::rotDeg + 40.f;
}

Cannon::Cannon(sf::Vector2f _pos, float _rotSpeed, float _rotDeg)
{
	Cannon::pos = { 100.f, 100.f };
	Cannon::shootCooldown = 1.f;
	Cannon::rotSpeed = _rotSpeed;
	Cannon::rotDeg = _rotDeg;
	Cannon::rot_MIN = _rotDeg - 40.f;
	Cannon::rot_MAX = _rotDeg + 40.f;
}

Cannon::Cannon(enumBienGuez _type) // warnings? shut
{
	switch (_type)
	{
	default:
		std::cout << "Please enter a correct Cannon type (got " << _type << ", expected 1 or 2)." << std::endl;
		return;
	case BIGCANNON:
		Cannon::pos = { 0.f, -50.f };
		Cannon::shootCooldown = 0.9f;
		Cannon::rotSpeed = 20.f;
		Cannon::rotDeg = 0.f;
		Cannon::rot_MIN = Cannon::rotDeg - 40.f;
		Cannon::rot_MAX = Cannon::rotDeg + 40.f;
		break;
	case SMOLCANNON:
		Cannon::pos = { 0.f, 50.f };
		Cannon::shootCooldown = 0.9f;
		Cannon::rotSpeed = 80.f;
		Cannon::rotDeg = 180.f;
		Cannon::rot_MIN = Cannon::rotDeg - 40.f;
		Cannon::rot_MAX = Cannon::rotDeg + 40.f;
		break;
	}
}

Cannon::~Cannon()
{
	// Destroy something idunno
}

inline float Cannon::getShootCooldown() { return shootCooldown; }

inline float Cannon::getRotDegrees() { return rotDeg;  }

inline void Cannon::setShootCooldown(float _shootCooldown) { shootCooldown = _shootCooldown; }

inline void Cannon::setRotDegrees(float _rotDegrees) { rotDeg = _rotDegrees; }

void Cannon::Update()
{
	// PLAYER POS
}

void Cannon::Rotate(int _dir)
{
	if (!_dir) return;
	rotDeg = std::max(rot_MIN, std::min(rot_MAX, rotDeg + _dir * rotSpeed * getDeltaTime()));
}

void Cannon::Shoot()
{
	// Call Bullet
}


void Cannon::Display(sf::RenderWindow& _window)
{
	holder::sprite.setPosition(Mouse::getRelativeMousePos() + pos);
	holder::sprite.setOrigin(holder::texture.getSize().x * 0.5f, holder::texture.getSize().y * 0.5f);
	holder::sprite.setRotation(rotDeg);
	holder::sprite.setTexture(holder::texture);
	_window.draw(holder::sprite);
}
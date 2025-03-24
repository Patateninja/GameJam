#include <iostream>

#include "Cannon.hpp"
#include "Player.hpp"
#include "Math.hpp"
#include "Tir.hpp"
#include "UI.hpp"

#define smallGunXOffset 25.f // HARD, GET FROM SPRITE
#define smallGunYOffset 85.f // HARD, GET FROM SPRITE
#define bigGunYOffset 35.f   // HARD, GET FROM SPRITE

namespace {
	sf::Sprite spriteCannon;
	sf::Texture bigCannonTexture;
	sf::Texture smallCannon1Texture;
	sf::Texture smallCannon2Texture;

	sf::Vector2f smallGun1OffSet = { -smallGunXOffset, -smallGunYOffset };
	sf::Vector2f smallGun2OffSet = { smallGunXOffset, -smallGunYOffset };
	sf::Vector2f bigGunOffSet = { 0.f, bigGunYOffset };

	sf::Vector2f smallGun1MuzzleL = { -10, -39 };  // HARD, GET FROM SPRITE
	sf::Vector2f smallGun1MuzzleR = { 15, -39 }; // HARD, GET FROM SPRITE
	sf::Vector2f smallGun2MuzzleL = { 10, -39 };  // HARD, GET FROM SPRITE
	sf::Vector2f smallGun2MuzzleR = { -15, -39 }; // HARD, GET FROM SPRITE
	sf::Vector2f bigGunMuzzle = { 0, -137 };     // HARD, GET FROM SPRITE

	sf::RectangleShape rect;
}

void initCannon()
{
	rect.setSize(sf::Vector2f(1, 1));
	bigCannonTexture.loadFromFile("../Ressources/Textures/cannonBig.png");
	smallCannon1Texture.loadFromFile("../Ressources/Textures/cannon1Small.png");
	smallCannon2Texture.loadFromFile("../Ressources/Textures/cannon2Small.png");
}

Cannon::Cannon()
{
	Cannon::type = BIGCANNON;
	Cannon::shootCooldown = 1.f;
	Cannon::damage = 1;
	Cannon::rotSpeed = 80.f;
	Cannon::rotDeg = 180.f;
	Cannon::rot_MIN = rotDeg - 40.f;
	Cannon::rot_MAX = rotDeg + 40.f;
}

Cannon::Cannon(enumBienGuez _type, float _shootCooldown, float _rotSpeed, float _rotDeg)
{
	Cannon::type = _type;
	Cannon::shootCooldown = _shootCooldown;
	Cannon::damage = 1;
	Cannon::rotSpeed = _rotSpeed;
	Cannon::rotDeg = _rotDeg;
	Cannon::rot_MIN = rotDeg - 40.f;
	Cannon::rot_MAX = rotDeg + 40.f;
}

Cannon::Cannon(enumBienGuez _type) // warnings? shut
{
	switch (_type)
	{
		default:
			std::cout << "Please enter a correct Cannon type (got " << _type << ", expected 0 or 1)." << std::endl;
			return;
		case BIGCANNON:
			Cannon::shootCooldown = 1.f;
			Cannon::damage = 20;
			Cannon::rotSpeed = 30.f;
			Cannon::rotDeg = 180.f;
			Cannon::rot_MIN = rotDeg - 25.f;
			Cannon::rot_MAX = rotDeg + 25.f;
			break;
		case SMOLCANNON1:
			Cannon::shootCooldown = 0.1f;
			Cannon::damage = 1;
			Cannon::rotSpeed = 75.f;
			Cannon::rotDeg = 0.f;
			Cannon::rot_MIN = rotDeg - 35.f;
			Cannon::rot_MAX = rotDeg + 35.f;
			break;
		case SMOLCANNON2:
			Cannon::shootCooldown = 0.1f;
			Cannon::damage = 1;
			Cannon::rotSpeed = 75.f;
			Cannon::rotDeg = 0.f;
			Cannon::rot_MIN = rotDeg - 35.f;
			Cannon::rot_MAX = rotDeg + 35.f;
			break;
	}
	Cannon::type = _type;
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
	shootTimer += getDeltaTime();
	float plrRot = Player::GetPlayerRotation();
	sf::Vector2f plrPos = Player::GetPlayerPosition();
	

	switch (type)
	{
	case BIGCANNON:
		origin = Math::mult2(static_cast<sf::Vector2f>(bigCannonTexture.getSize()), { 0.5f, 1.f }); // HARD, GET MAGIC MULT VALUES FROM SPRITE
		basePos = plrPos + Math::rotateVector(bigGunOffSet, DEG2RAD * plrRot);
		muzzleLPos = basePos + Math::rotateVector(bigGunMuzzle, DEG2RAD * (plrRot - rotDeg));
		muzzleRPos = basePos + Math::rotateVector(bigGunMuzzle, DEG2RAD * (plrRot - rotDeg));
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::RShift) && UI::canBigShot()) Shoot(TypeTir::GROS);
		break;
	case SMOLCANNON1:
		origin = Math::mult2(static_cast<sf::Vector2f>(smallCannon1Texture.getSize()), { 0.5f, 0.8f }); // HARD, GET MAGIC MULT VALUES FROM SPRITE
		basePos = plrPos + Math::rotateVector(smallGun1OffSet, DEG2RAD * plrRot);
		muzzleLPos = basePos + Math::rotateVector(smallGun1MuzzleL, DEG2RAD * (plrRot - rotDeg));
		muzzleRPos = basePos + Math::rotateVector(smallGun1MuzzleR, DEG2RAD * (plrRot - rotDeg));
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::LShift) && UI::canSmallShot()) Shoot(TypeTir::PETIT);
		break;
	case SMOLCANNON2:
		origin = Math::mult2(static_cast<sf::Vector2f>(smallCannon2Texture.getSize()), { 0.5f, 0.8f }); // HARD, GET MAGIC MULT VALUES FROM SPRITE
		basePos = plrPos + Math::rotateVector(smallGun2OffSet, DEG2RAD * plrRot);
		muzzleLPos = basePos + Math::rotateVector(smallGun2MuzzleL, DEG2RAD * (plrRot - rotDeg));
		muzzleRPos = basePos + Math::rotateVector(smallGun2MuzzleR, DEG2RAD * (plrRot - rotDeg));
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::LShift) && UI::canSmallShot()) Shoot(TypeTir::PETIT);
		break;
	}
}

void Cannon::Rotate(int _dir)
{
	if (!_dir) return;
	rotDeg = std::max(rot_MIN, std::min(rot_MAX, rotDeg + _dir * rotSpeed * getDeltaTime()));
}

void Cannon::Shoot(TypeTir _type)
{
	

	if (shootTimer < shootCooldown)
	{
		return;
	}

	std::list<Tir>& t = getTirList();

	t.push_back(Tir(Player::GetPlayerRotation() - rotDeg, muzzleLPos, _type));
	if (!_type == GROS)
	{
		Sound::PlaySound("mitrailleuse");
		UI::SmallShot();
		t.push_back(Tir(Player::GetPlayerRotation() - rotDeg, muzzleRPos, _type));
	}
	else
	{
		Sound::PlaySound("canon");
		UI::BigShot();
	}
	shootTimer = 0.f;
}


void Cannon::Display(sf::RenderWindow& _window)
{
	float plrRot = Player::GetPlayerRotation();

	spriteCannon.setOrigin(origin);
	spriteCannon.setPosition(basePos);

	rect.setPosition(muzzleLPos);
	rect.setRotation(plrRot - rotDeg);
	_window.draw(rect);
	rect.setPosition(muzzleRPos);
	_window.draw(rect);

	switch (type)
	{
		case BIGCANNON:
			spriteCannon.setTexture(bigCannonTexture, true);
			break;
		case SMOLCANNON1:
			spriteCannon.setTexture(smallCannon1Texture, true);
			break;
		case SMOLCANNON2:
			spriteCannon.setTexture(smallCannon2Texture, true);
			break;
	}

	spriteCannon.setRotation(plrRot - rotDeg);
	_window.draw(spriteCannon);
}
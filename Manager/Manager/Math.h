#pragma once
#include "tools.h"
#define PI 3.14159265359
#define EPSILON 0.0001

namespace Math
{
	float degToRad(float deg);
	float radToDeg(float rad);
	float distance(sf::Vector2f a, sf::Vector2f b);
	float magnitude(sf::Vector2f a);
	sf::Vector2f normalize(sf::Vector2f a);
	float dot(sf::Vector2f a, sf::Vector2f b);
	float cross(sf::Vector2f a, sf::Vector2f b);
	float angleBetweenVectors(sf::Vector2f a, sf::Vector2f b);
	sf::Vector2f rotateVector(sf::Vector2f a, float angle);
	sf::Vector2f lerp(sf::Vector2f a, sf::Vector2f b, float t);
	sf::Vector2f slerp(sf::Vector2f a, sf::Vector2f b, float t);
	sf::Vector2f nlerp(sf::Vector2f a, sf::Vector2f b, float t);
	sf::Vector2f reflect(sf::Vector2f a, sf::Vector2f normal);
	sf::Vector2f project(sf::Vector2f a, sf::Vector2f b);
	sf::Vector2f reject(sf::Vector2f a, sf::Vector2f b);
	sf::Vector2f perp(sf::Vector2f a);
	sf::Vector2f perpClockwise(sf::Vector2f a);
	sf::Vector2f perpCounterClockwise(sf::Vector2f a);
	sf::Vector2f truncate(sf::Vector2f a, float max);
	sf::Vector2f clamp(sf::Vector2f a, float min, float max);
	sf::Vector2f smoothDamp(sf::Vector2f current, sf::Vector2f target, sf::Vector2f& velocity, float smoothTime, float maxSpeed, float deltaTime);
	bool isEquals(float a, float b);
	bool isZero(float a);
	bool isZero(sf::Vector2f a);
	bool isEquals(sf::Vector2f a, sf::Vector2f b);
}
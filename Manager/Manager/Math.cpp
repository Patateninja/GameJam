#include "Math.h"

float Math::distance(sf::Vector2f a, sf::Vector2f b)
{
	return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

float Math::magnitude(sf::Vector2f a)
{
	return sqrt(pow(a.x, 2) + pow(a.y, 2));
}

sf::Vector2f Math::normalize(sf::Vector2f a)
{
	float mag = magnitude(a);
	return sf::Vector2f(a.x / mag, a.y / mag);
}

float Math::dot(sf::Vector2f a, sf::Vector2f b)
{
	return a.x * b.x + a.y * b.y;
}

float Math::cross(sf::Vector2f a, sf::Vector2f b)
{
	return a.x * b.y - a.y * b.x;
}

float Math::angleBetweenVectors(sf::Vector2f a, sf::Vector2f b)
{
	return acos(dot(a, b) / (magnitude(a) * magnitude(b)));
}

float Math::length(sf::Vector2f v)
{
	return sqrtf(v.x * v.x + v.y * v.y);
}

sf::Vector2f Math::mult2(sf::Vector2f v, float a)
{
	return sf::Vector2f(v.x*a, v.y*a);
}

sf::Vector2f Math::mult2(sf::Vector2f a, sf::Vector2f b)
{
	return sf::Vector2f(a.x * b.x, a.y * b.y);
}

sf::Vector2f Math::rotateVector(sf::Vector2f a, float angle)
{

	return sf::Vector2f(a.x * cos(angle) - a.y * sin(angle), a.x * sin(angle) + a.y * cos(angle));
}

sf::Vector2f Math::lerp(sf::Vector2f a, sf::Vector2f b, float t)
{
	return a + t * (b - a);
}

float Math::lerp2D(float a, float b, float t)
{
	return a + t * (b - a);
}

sf::Vector2f Math::slerp(sf::Vector2f a, sf::Vector2f b, float t)
{
	float angle = angleBetweenVectors(a, b);
	return rotateVector(a, angle * t);
}

sf::Vector2f Math::nlerp(sf::Vector2f a, sf::Vector2f b, float t)
{
	return normalize(lerp(a, b, t));
}

sf::Vector2f Math::reflect(sf::Vector2f a, sf::Vector2f normal)
{
	return a - 2 * dot(a, normal) * normal;
}

sf::Vector2f Math::perp(sf::Vector2f a)
{
	return sf::Vector2f(-a.y, a.x);
}

sf::Vector2f Math::perpClockwise(sf::Vector2f a)
{
	return sf::Vector2f(a.y, -a.x);
}

sf::Vector2f Math::perpCounterClockwise(sf::Vector2f a)
{
	return sf::Vector2f(-a.y, a.x);
}

sf::Vector2f Math::truncate(sf::Vector2f a, float max)
{
	if (magnitude(a) > max)
	{
		return normalize(a) * max;
	}
	return a;
}

sf::Vector2f Math::clamp(sf::Vector2f a, float min, float max)
{
	return sf::Vector2f(std::clamp(a.x, min, max), std::clamp(a.y, min, max));
}

sf::Vector2f Math::smoothDamp(sf::Vector2f current, sf::Vector2f target, sf::Vector2f& velocity, float smoothTime, float maxSpeed, float deltaTime)
{
	float t = 2 / smoothTime;
	float omega = t;
	float x = omega * deltaTime;
	float exp = 1 / (1 + x + 0.48 * x * x + 0.235 * x * x * x);
	sf::Vector2f change = (current - target) * exp;
	sf::Vector2f temp = target + (current - target) * exp;
	sf::Vector2f tempVelocity = (velocity + change) * exp;
	velocity = (velocity + change) * exp;
	return temp;
}

sf::Vector2f Math::polarToCartesian(sf::Vector2f v)
{
	return { v.x * std::cos(v.y), v.y * std::sin(v.y) };
}

sf::Vector2f Math::cartesianToPolar(sf::Vector2f v)
{
	return { Math::length(v), std::atan2(v.y, v.x) };
}

bool Math::isEquals(float a, float b)
{
	return fabs(a - b) < EPSILON;
}

bool Math::isZero(float a)
{
	return fabs(a) < EPSILON;
}

bool Math::isZero(sf::Vector2f a)
{
	return magnitude(a) < EPSILON;
}

bool Math::isEquals(sf::Vector2f a, sf::Vector2f b)
{
	return isZero(a - b);
}

bool Math::pointCircle(sf::Vector2f _point, sf::Vector2f _circle, float _radius)
{
	sf::Vector2f distTarget = _point - _circle;

	if (Math::length(distTarget) <= _radius) return true;
	return false;
}
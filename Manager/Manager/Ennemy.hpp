#pragma once
#include "Tools.h"
#include "Math.h"
#include "Player.h"
#include "Tir.h"
#include <ranges>
#include <list>

typedef enum EnemyClass
{
	NORMAL,
	TANK,
	SPEEDSTER,
} EnemyClass;

typedef enum ObstacleType
{
	CACTUS,
	ROCK,
	BIG_ROCK,
} ObstacleType;


struct Obstacle
{
	sf::Texture m_text;
		sf::RectangleShape m_Rect;
		float thresholdAvoidance = 0.f;

		Obstacle(sf::Vector2f _pos, ObstacleType _type)
		{
			this->m_Rect.setPosition(_pos);

			switch (_type)
			{
				case CACTUS :
					this->m_text.loadFromFile("..\\Ressources\\Textures\\cactus_L70_H62.png");
					this->m_Rect.setTexture(&m_text);
					this->m_Rect.setSize(sf::Vector2f(70.f,62.f));
					this->m_Rect.setOrigin(sf::Vector2f(35.f,31.));
					this->thresholdAvoidance = 52.5f;
					break;
				case ROCK :
					this->m_text.loadFromFile("..\\Ressources\\Textures\\caillou_L115_H87.png");
					this->m_Rect.setTexture(&m_text);
					this->m_Rect.setSize(sf::Vector2f(115.f,87.f));
					this->m_Rect.setOrigin(sf::Vector2f(57.5f,43.5f));
					this->thresholdAvoidance = 86.25f;
					break;
				case BIG_ROCK :
					this->m_text.loadFromFile("..\\Ressources\\Textures\\gros_rocher_L318_H167.png");
					this->m_Rect.setTexture(&m_text);
					this->m_Rect.setSize(sf::Vector2f(318.f,167.f));
					this->m_Rect.setOrigin(sf::Vector2f(159.f,83.5f));
					this->thresholdAvoidance = 208.5f;
					break;
			}
		}
		

		sf::Vector2f GetPosition()
		{
			return this->m_Rect.getGlobalBounds().getPosition() + this->m_Rect.getOrigin();
		}

		void Draw(sf::RenderWindow& _window)
		{
			_window.draw(this->m_Rect);
		}
};

void CreateObstacle(sf::Vector2f _pos, ObstacleType _type, std::vector<Obstacle*>& _list);

class Enemy
{
	private :
		sf::RectangleShape m_Rect;
		sf::Vector2f m_pos;
		EnemyClass m_class;
		float m_hp;
		float m_speed;
		sf::Vector2f m_velocity;
		float angle;

	public :
		Enemy(sf::Vector2f pos, EnemyClass type);
		~Enemy();

		bool Update(std::vector<Obstacle*> _obstacleList, std::list<Enemy*>& _list);
		void Display(sf::RenderWindow& window);

		//Getters
		inline sf::Vector2f getPos() { return m_pos; };
		inline EnemyClass getClass() { return m_class; };
		inline sf::Vector2f getVelocity() { return m_velocity; };
		inline float getAngle() { return angle; };
		inline int getPv() { return m_hp; };
	
		//Setters
		inline void setPv(int _pv) { m_hp = _pv; };
		inline void setPos(sf::Vector2f _pos) { m_pos = _pos; };
		inline void setVelocity(sf::Vector2f _velocity) { m_velocity = _velocity; };
		inline void setAngle(float _angle) { angle = _angle; };

		//IA
		void Seek(sf::Vector2f _target, Obstacle* _closestObstacle);

		//Game
		void CheckForHit();
		void TakeDamage(int _damage);
		void Die(std::list<Enemy*>& _list);
};

void Spawn(sf::Vector2f _pos, EnemyClass _type, std::list<Enemy*>& _list);
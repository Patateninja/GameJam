#include "Player.h"

namespace Player
{
	float moveSpeed = 5.0f;
	float rotationSpeed = 5.0f;

	bool isMovingUp = false;
	bool isMovingDown = false;

	bool isMovingUpRight = false;
	bool isMovingUpLeft = false;

	bool isMovingDownRight = false;
	bool isMovingDownLeft = false;

	bool isRotateLeft = false;
	bool isRotateRight = false;

	sf::Sprite playerSprite;
	sf::Texture playerTexture;

	sf::Vector2f direction(0.f, 1.f);

	void UpdateInput()
	{

#pragma region SoloInput

		// MoveUp Right
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			isMovingUpRight = true;
		}
		else
		{
			isMovingUpRight = false;
		}

		// MoveDown Right
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Z) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			isMovingDownRight = true;
		}
		else
		{
			isMovingDownRight = false;
		}

		// MoveUp Left
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Z) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			isMovingUpLeft = true;
		}
		else
		{
			isMovingUpLeft = false;
		}

		// MoveDown Left
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Z) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			isMovingDownLeft = true;
		}
		else
		{
			isMovingDownLeft = false;
		}

#pragma endregion

#pragma region DuoInput

		// Rotate Left
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) &&
			sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			isRotateLeft = true;
		}
		else
		{
			isRotateLeft = false;
		}

		// Rotate Right
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
			sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Z) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			isRotateRight = true;
		}
		else
		{
			isRotateRight = false;
		}

		// MoveUp
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) &&
			sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			isMovingUp = true;
		}
		else
		{
			isMovingUp = false;
		}

		// MoveDown
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
			sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Z) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			isMovingDown = true;
		}
		else
		{
			isMovingDown = false;
		}

#pragma endregion

	}

	void PlayerDirection()
	{
		// Mise à jour de la direction du joueur selon l'angle de rotation
		float angle = playerSprite.getRotation();
		direction.x = std::sin(angle * 3.14159f / 180.f);  // Conversion de l'angle en radians et calcul du cosinus
		direction.y = -std::cos(angle * 3.14159f / 180.f); // Le signe négatif pour l'axe Y (sinon l'orientation est inversée)
	}

	void UpdatePosition()
	{

		PlayerDirection();

#pragma region SoloInput

		// MoveUp Right
		if (isMovingUpRight)
		{
			playerSprite.move(-direction * moveSpeed);
			playerSprite.setRotation(playerSprite.getRotation() - rotationSpeed);  // Tourner à gauche
		}

		// MoveDown Right
		if (isMovingDownRight)
		{
			playerSprite.move(direction * moveSpeed);
			playerSprite.setRotation(playerSprite.getRotation() + rotationSpeed);  // Tourner à droite
		}

		// MoveUp Left
		if (isMovingUpLeft)
		{
			playerSprite.move(-direction * moveSpeed);
			playerSprite.setRotation(playerSprite.getRotation() + rotationSpeed);  // Tourner à droite
		}

		// MoveDown Right
		if (isMovingDownLeft)
		{
			playerSprite.move(direction * moveSpeed);
			playerSprite.setRotation(playerSprite.getRotation() - rotationSpeed);  // Tourner à droite
		}

#pragma endregion

#pragma region DuoInput

		// Rotate Left
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) &&
			sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			playerSprite.rotate(-rotationSpeed);  // Rotation lente à gauche
		}

		// Rotate Right
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
			sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Z) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			playerSprite.rotate(rotationSpeed);  // Rotation lente à droite
		}

		// MoveUp
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) &&
			sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			playerSprite.move(-direction * moveSpeed);
		}

		// MoveDown
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
			sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Z) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			playerSprite.move(direction * moveSpeed);
		}

#pragma endregion

	}
}

void Player::Init()
{
	playerTexture.loadFromFile("../Ressources/Textures/Player.png");
	playerSprite.setTexture(playerTexture);
	playerSprite.setPosition(400, 400);

	// Set the origin of the sprite to the center
	playerSprite.setOrigin(playerSprite.getGlobalBounds().width / 2, playerSprite.getGlobalBounds().height / 2);

	// Scale the sprite
	playerSprite.setScale(0.5f, 0.5f);
}

void Player::Update()
{
	UpdateInput();
	UpdatePosition();
}


void Player::Display(sf::RenderWindow& _window)
{
	_window.draw(playerSprite);
}


#include "Player.h"
#include "Math.h"

#define track1Length 128
#define track2Length 156

#define track1WCenter 29
#define track2WCenter 32

namespace Player
{
	float moveSpeed = 175.0f;
	float rotationSpeed = 75.0f;
	sf::Vector2f position = { 400.f, 400.f };
	float rotation = 0;

	bool isMovingUp = false;
	bool isMovingDown = false;

	bool isMovingUpRight = false;
	bool isMovingUpLeft = false;

	bool isMovingDownRight = false;
	bool isMovingDownLeft = false;

	bool isRotateLeft = false;
	bool isRotateRight = false;

	sf::Sprite playerSprite;
	sf::Sprite trackLSprite;
	sf::Sprite trackRSprite;
	sf::Texture playerTexture;
	sf::Texture trackTexture;

	sf::Vector2f direction(0.f, 1.f);

	void UpdateInput()
	{

#pragma region SoloInput

		// MoveUp Right
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down))
		{
			isMovingUpRight = true;
		}
		else
		{
			isMovingUpRight = false;
		}

		// MoveDown Right
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down))
		{
			isMovingDownRight = true;
		}
		else
		{
			isMovingDownRight = false;
		}

		// MoveUp Left
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down))
		{
			isMovingUpLeft = true;
		}
		else
		{
			isMovingUpLeft = false;
		}

		// MoveDown Left
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up))
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Z) &&
			sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up))
		{
			isRotateLeft = true;
		}
		else
		{
			isRotateLeft = false;
		}

		// Rotate Right
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S) &&
			sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down))
		{
			isRotateRight = true;
		}
		else
		{
			isRotateRight = false;
		}

		// MoveUp
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W) &&
			sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down))
		{
			isMovingUp = true;
		}
		else
		{
			isMovingUp = false;
		}

		// MoveDown
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S) &&
			sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up))
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
		direction.x = std::sin(angle * DEG2RAD);  // Conversion de l'angle en radians et calcul du cosinus
		direction.y = -std::cos(angle * DEG2RAD); // Le signe négatif pour l'axe Y (sinon l'orientation est inversée)
	}

	void UpdatePosition()
	{

		PlayerDirection();

#pragma region SoloInput

		// MoveUp Right
		if (isMovingUpRight)
		{
			position -= direction * moveSpeed * getDeltaTime();
			rotation -= rotationSpeed * getDeltaTime();  // Tourner à gauche
		}

		// MoveDown Right
		if (isMovingDownRight)
		{
			position += direction * moveSpeed * getDeltaTime();
			rotation += rotationSpeed * getDeltaTime();  // Tourner à droite
		}

		// MoveUp Left
		if (isMovingUpLeft)
		{
			position -= direction * moveSpeed * getDeltaTime();
			rotation += rotationSpeed * getDeltaTime();  // Tourner à droite
		}

		// MoveDown Right
		if (isMovingDownLeft)
		{
			position += direction * moveSpeed * getDeltaTime();
			rotation -= rotationSpeed * getDeltaTime();  // Tourner à droite
		}

#pragma endregion

#pragma region DuoInput

		// Rotate Left
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W) &&
			sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up))
		{
			rotation -= rotationSpeed * getDeltaTime();  // Rotation lente à gauche
		}

		// Rotate Right
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S) &&
			sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down))
		{
			rotation += rotationSpeed * getDeltaTime();  // Rotation lente à droite
		}

		// MoveUp
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W) &&
			sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down))
		{
			position -= direction * moveSpeed * getDeltaTime();
		}

		// MoveDown
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S) &&
			sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up))
		{
			position += direction * moveSpeed * getDeltaTime();
		}

#pragma endregion

	}
}


float Player::GetPlayerSpeed()
{
	return moveSpeed;
}

sf::Vector2f Player::GetPlayerPosition()
{
	return Player::playerSprite.getPosition();
}

float Player::GetPlayerRotation()
{
	return Player::playerSprite.getRotation();
}


void Player::SetPlayerSpeed(float value)
{
	moveSpeed = value;
}

float Player::GetRotateSpeed()
{
	return rotationSpeed;
}

void Player::SetRotateSpeed(float value)
{
	rotationSpeed = value;
}

void Player::Init()
{
	playerTexture.loadFromFile("../Ressources/Textures/car.png");
	trackTexture.loadFromFile("../Ressources/Textures/track.png");
	playerSprite.setTexture(playerTexture);
	trackLSprite.setTexture(trackTexture);

	// Set the origin of the sprite to the center
	playerSprite.setOrigin(playerSprite.getGlobalBounds().getSize() * 0.5f);
	trackLSprite.setOrigin(sf::Vector2f(-50.f, 64.f));
	trackRSprite.setOrigin(sf::Vector2f(80.f, 78.f));
	trackLSprite.setTextureRect(sf::IntRect(0, 0, 35, 310));
	trackRSprite.setTextureRect(sf::IntRect(0, 0, 35, 310));

	// Scale the sprite
	playerSprite.setScale(0.5f, 0.5f);
	trackLSprite.setScale(0.5f, 0.5f);
	trackRSprite.setScale(0.5f, 0.5f);
}

void Player::Update()
{
	UpdateInput();
	UpdatePosition();

	playerSprite.setPosition(position);
	playerSprite.setRotation(rotation);

#pragma region Anim
	static float timer = 0.f;
	static int animX = 0;
	timer += getDeltaTime();

	if (timer > 0.2f)
	{
		timer = 0.f;
		animX = !animX;
		if (isMovingUp)
		{
			trackLSprite.setTextureRect(sf::IntRect(track1WCenter * animX, 0, track1WCenter, track1Length));
			trackRSprite.setTextureRect(sf::IntRect(track2WCenter * animX, 0, track2WCenter, track2Length));
		}
		else if (isMovingDown)
		{
			trackLSprite.setTextureRect(sf::IntRect(track1WCenter * !animX, 0, track1WCenter, track1Length));
			trackRSprite.setTextureRect(sf::IntRect(track2WCenter * !animX, 0, track2WCenter, track2Length));
		}
		else if (isMovingUpRight)
		{
			trackRSprite.setTextureRect(sf::IntRect(track2WCenter * animX, 0, track2WCenter, track2Length));
		}
		else if (isMovingUpLeft)
		{
			trackLSprite.setTextureRect(sf::IntRect(track1WCenter * animX, 0, track1WCenter, track1Length));
		}
		else if (isMovingDownRight)
		{
			trackRSprite.setTextureRect(sf::IntRect(track2WCenter * !animX, 0, track2WCenter, track2Length));
		}
		else if (isMovingDownLeft)
		{
			trackLSprite.setTextureRect(sf::IntRect(track1WCenter * !animX, 0, track1WCenter, track1Length));
		}
		else if (isRotateLeft)
		{
			trackLSprite.setTextureRect(sf::IntRect(track1WCenter * !animX, 0, track1WCenter, track1Length));
			trackRSprite.setTextureRect(sf::IntRect(track2WCenter * animX, 0, track2WCenter, track2Length));
		}
		else if (isRotateRight)
		{
			trackLSprite.setTextureRect(sf::IntRect(track1WCenter * animX, 0, track1WCenter, track1Length));
			trackRSprite.setTextureRect(sf::IntRect(track2WCenter * !animX, 0, track2WCenter, track2Length));
		}
	}
#pragma endregion
}


void Player::Display(sf::RenderWindow& _window)
{
	_window.draw(playerSprite);
	trackLSprite.setPosition(position + Math::rotateVector(sf::Vector2f(-80.f, 50.f), rotation * DEG2RAD));
	trackLSprite.setRotation(rotation);
	trackLSprite.setColor(sf::Color::Red);

	trackRSprite.setPosition(position + Math::rotateVector(sf::Vector2f(80.f, -50.f), rotation * DEG2RAD));
	trackRSprite.setRotation(rotation);
	trackRSprite.setColor(sf::Color::Blue);

	_window.draw(trackLSprite);
	_window.draw(trackRSprite);
	
}


#include "Player.h"
#include "Math.h"



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
	sf::Sprite track1Sprite;
	sf::Sprite track2Sprite;
	sf::Texture playerTexture;
	sf::Texture track1Texture;
	sf::Texture track2Texture;

	sf::Vector2f direction(0.f, 1.f);

	void UpdateInput()
	{

#pragma region SoloInput

		// MoveUp Right
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
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
			!sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
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
			!sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
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
			!sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
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
			!sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
			!sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			isRotateRight = true;
		}
		else
		{
			isRotateRight = false;
		}

		// MoveUp
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
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
			!sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
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
	track1Texture.loadFromFile("../Ressources/Textures/track1.png");
	track2Texture.loadFromFile("../Ressources/Textures/track2.png");
	playerSprite.setTexture(playerTexture);
	track1Sprite.setTexture(track1Texture);
	track2Sprite.setTexture(track2Texture);

	// Set the origin of the sprite to the center
	playerSprite.setOrigin(playerSprite.getGlobalBounds().getSize() * 0.5f);
	track1Sprite.setOrigin(sf::Vector2f(30, 64));
	track1Sprite.setOrigin(sf::Vector2f(-30, 78));
	track2Sprite.setOrigin(track2Sprite.getGlobalBounds().getSize() * 0.5f);
	track1Sprite.setTextureRect(sf::IntRect(30, 0, 29, 128));
	track2Sprite.setTextureRect(sf::IntRect(32, 0, 32, 156));

	// Scale the sprite
	playerSprite.setScale(0.5f, 0.5f);
	track1Sprite.setScale(0.7f, 0.7f);
	track2Sprite.setScale(0.7f, 0.7f);
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
			track1Sprite.setTextureRect(sf::IntRect(30 * animX, 0, 29, 128));
			track2Sprite.setTextureRect(sf::IntRect(32 * animX, 0, 32, 156));
		}
		else if (isMovingDown)
		{
			track1Sprite.setTextureRect(sf::IntRect(30 * !animX, 0, 29, 128));
			track2Sprite.setTextureRect(sf::IntRect(32 * !animX, 0, 32, 156));
		}
		else if (isMovingUpRight)
		{
			track2Sprite.setTextureRect(sf::IntRect(32 * animX, 0, 32, 156));
		}
		else if (isMovingUpLeft)
		{
			track1Sprite.setTextureRect(sf::IntRect(30 * animX, 0, 29, 128));
		}
		else if (isMovingDownRight)
		{
			track2Sprite.setTextureRect(sf::IntRect(32 * !animX, 0, 32, 156));
		}
		else if (isMovingDownLeft)
		{
			track1Sprite.setTextureRect(sf::IntRect(30 * !animX, 0, 29, 128));
		}
		else if (isRotateLeft)
		{
			track1Sprite.setTextureRect(sf::IntRect(30 * !animX, 0, 29, 128));
			track2Sprite.setTextureRect(sf::IntRect(32 * animX, 0, 32, 156));
		}
		else if (isRotateRight)
		{
			track1Sprite.setTextureRect(sf::IntRect(30 * animX, 0, 29, 128));
			track2Sprite.setTextureRect(sf::IntRect(32 * !animX, 0, 32, 156));
		}
	}
#pragma endregion
}


void Player::Display(sf::RenderWindow& _window)
{
	_window.draw(playerSprite);
	for (int i = 0; i < 2; i++)
	{
		track1Sprite.setPosition(position + sf::Vector2f(0, i*50.f));
		track1Sprite.setRotation(rotation);

		track2Sprite.setPosition(position + sf::Vector2f(0, i * 50.f));
		track2Sprite.setRotation(rotation);

		_window.draw(track1Sprite);
		_window.draw(track2Sprite);
	}
}


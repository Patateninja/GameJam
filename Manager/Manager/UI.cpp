#include "UI.h"
#include "Ultime.h"


namespace UI
{

	#pragma region Variables

	#pragma region KeyAnimation

	sf::Texture textureKey;
	sf::Texture textureKeyTurnAnim;

	sf::Sprite spriteKey1;
	sf::Sprite spriteKey2;

	sf::IntRect rectKeyAnim1(0, 0, 257, 83);
	sf::IntRect rectKeyAnim2(0, 0, 257, 83);

	sf::IntRect rectKey1TurnAnim(0, 0, 108, 83);
	sf::IntRect rectKey2TurnAnim(0, 0, 108, 83);

	sf::Vector2f positionKey1(240.f, 25.f);
	sf::Vector2f positionKey2(1720.f, 25.f);

	#pragma endregion

	sf::Color MetalicGrey = sf::Color(69, 69, 69);
	sf::RectangleShape rect;

	#pragma region Sprite

		sf::Sprite sprite;
		sf::Sprite spriteTwo;
		sf::Sprite spriteThree;

	#pragma endregion

	#pragma region Textures

		sf::Texture texture;
		sf::Texture textureTwo;
		sf::Texture textureThree;

	#pragma endregion

	#pragma region int

		int number = 101; // 101
		int secondNumber = 0;
		int thirdNumberOne = 251;
		int thirdNumberTwo = 251;

	#pragma endregion

	#pragma region float

		float timerOverLoadOne = 0;
		float timerOverLoadTwo = 0;

	#pragma endregion

	#pragma region bool

		bool IsOverLoadOne = false;
		bool IsOverLoadTwo = false;
		bool IsPlayerOneShooting = false;
		bool IsPlayerTwoShooting = false;
		bool isPowerUpReady = false;

		bool keyStartUlt = false;

	#pragma endregion

	#pragma endregion

	#pragma region Fonction Private

		void drawCircle(sf::RenderWindow& window, sf::Vector2f pos, float radius, sf::Color color)
		{
			if (number <= 0)
				isPowerUpReady = true;
			sf::VertexArray vertex(sf::TriangleFan, number + 1);
			vertex[0].position = pos;
			vertex[0].color = color;
			for (int i = 0; i < number; i++)
			{
				float angle = 2 * 3.14159265359 * i / 100 - 3.14159265359 / 2;
				vertex[i + 1].position = sf::Vector2f(pos.x + cos(angle) * radius, pos.y + sin(angle) * radius);
				vertex[i + 1].color = color;
			}
			window.draw(vertex);
		}

		void drawQuad(sf::RenderWindow& window, sf::Vector2f pos, float size, sf::Color color)
		{
			if (secondNumber == 37)
				std::cout << "Dead" << std::endl;
			sf::VertexArray vertex(sf::Quads, secondNumber * 4);
			pos.x -= secondNumber * 21;
			for (int i = 0; i < secondNumber; i++)
			{
				if (i == 0)
				{
					vertex[i * 4].position = sf::Vector2f(pos.x + 21 + i * 21, pos.y);
					vertex[i * 4].color = color;
				}
				else
				{
					vertex[i * 4].position = sf::Vector2f(pos.x + i * 21, pos.y);
					vertex[i * 4].color = color;
				}
				vertex[i * 4 + 1].position = sf::Vector2f(pos.x + i * 21 + 21, pos.y);
				vertex[i * 4 + 1].color = color;
				vertex[i * 4 + 2].position = sf::Vector2f(pos.x + i * 21 + 21, pos.y + size);
				vertex[i * 4 + 2].color = color;
				vertex[i * 4 + 3].position = sf::Vector2f(pos.x + i * 21, pos.y + size);
				vertex[i * 4 + 3].color = color;
			}
			window.draw(vertex);
		}

		void drawVerticalRectOne(sf::RenderWindow& window, sf::Vector2f pos, float size, sf::Color color)
		{
			if (thirdNumberOne < 0)
				IsOverLoadOne = true;
			rect.setSize(sf::Vector2f(size, 2));
			rect.setFillColor(color);
			rect.setPosition(pos);
			rect.setScale(1, thirdNumberOne + 1);
			window.draw(rect);
		}

		void drawVerticalRectTwo(sf::RenderWindow& window, sf::Vector2f pos, float size, sf::Color color)
		{
			if (thirdNumberTwo < 0)
				IsOverLoadTwo = true;
			rect.setSize(sf::Vector2f(size, 2));
			rect.setFillColor(color);
			rect.setPosition(pos);
			rect.setScale(1, thirdNumberTwo + 1);
			window.draw(rect);
		}

		void updateRect()
		{
			timerOverLoadOne += getDeltaTime();
			timerOverLoadTwo += getDeltaTime();
			if (IsOverLoadOne && timerOverLoadOne > 1.8f)
			{
				thirdNumberOne++;
				if (thirdNumberOne > 251)
				{
					thirdNumberOne = 251;
					IsOverLoadOne = false;
				}
			}

			if (IsOverLoadTwo && timerOverLoadTwo > 1.8f)
			{
				thirdNumberTwo++;
				if (thirdNumberTwo > 251)
				{
					thirdNumberTwo = 251;
					IsOverLoadTwo = false;
				}
			}

			if (!IsOverLoadOne && timerOverLoadOne > 0.1f && !IsPlayerOneShooting)
			{
				timerOverLoadOne = 0;
				thirdNumberOne++;
				if (thirdNumberOne > 251)
				{
					thirdNumberOne = 251;
				}
			}

			if (!IsOverLoadTwo && timerOverLoadTwo > 0.1f && !IsPlayerTwoShooting)
			{
				timerOverLoadTwo = 0;
				thirdNumberTwo++;
				if (thirdNumberTwo > 251)
				{
					thirdNumberTwo = 251;
				}
			}

			if (IsPlayerOneShooting && timerOverLoadOne > 0.8f)
			{
				timerOverLoadOne = 0;
				IsPlayerOneShooting = false;
			}

			if (IsPlayerTwoShooting && timerOverLoadTwo > 0.3f)
			{
				timerOverLoadTwo = 0;
				IsPlayerTwoShooting = false;
			}
		}

		void UpdateKeyAnim()
		{
			static bool key1Turn = false;
			static bool key2Turn = false;

			static bool key1Echec = false;
			static bool key2Echec = false;

			static bool key1Reverse = false;
			static bool key2Reverse = false;

			static float keyWaiterTimer = 2.f;
			static float keyWaiterUltimeTimer = 0.f;

			static float key1WaiterDisableTimer = 0.f;
			static float key2WaiterDisableTimer = 0.f;

			static float key1Timer = 0.f;
			static float key2Timer = 0.f;

			static bool key1Ulti = false;
			static bool key2Ulti = false;

			static bool key1Disable = false;
			static bool key2Disable = false;

			static bool keyDraw = false;

			

			if (isPowerUpReady)
			{
				if (number == 0)
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && !key1Disable)
					{
						key1Ulti = true;
					}

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl) && !key2Disable)
					{
						key2Ulti = true;
					}
				}



				if (key1Ulti)
				{
					// Key Position Animation
					positionKey1.x += 2.f;
					if (positionKey1.x >= 385.f)
						positionKey1.x = 385.f;
					spriteKey1.setPosition(positionKey1);

					// Key Rect Animation 
					rectKeyAnim1.width -= 2;
					if (rectKeyAnim1.width <= 109)
					{
						rectKeyAnim1.width = 109;
						key1Turn = true;
						key1Ulti = false;
					}
					spriteKey1.setTextureRect(rectKeyAnim1);


				}

				if (key2Ulti)
				{
					// Key Position Animation
					positionKey2.x -= 2.f;
					if (positionKey2.x <= 1570.f)
						positionKey2.x = 1570.f;
					spriteKey2.setPosition(positionKey2);

					// Key Rect Animation
					rectKeyAnim2.width -= 2;
					if (rectKeyAnim2.width <= 109)
					{
						rectKeyAnim2.width = 109;
						key2Turn = true;
						key2Ulti = false;
					}
					spriteKey2.setTextureRect(rectKeyAnim2);


				}

				if (key1Turn) key1Timer += getDeltaTime();
				if (key2Turn) key2Timer += getDeltaTime();


				// Turn Key 1 Animation
				if (key1Turn && key1Timer > 0.2f)
				{
					spriteKey1.setTexture(textureKeyTurnAnim);
					spriteKey1.setTextureRect(rectKey1TurnAnim);
					rectKey1TurnAnim.left += 109;
					if (rectKey1TurnAnim.left >= 109 * 4)
					{
						rectKey1TurnAnim.left = 109 * 4;
					}
					key1Timer = 0;
					
				}

				// Turn Key 2 Animation
				if (key2Turn && key2Timer > 0.2f)
				{
					spriteKey2.setTexture(textureKeyTurnAnim);
					spriteKey2.setTextureRect(rectKey2TurnAnim);

					rectKey2TurnAnim.left += 109;
					if (rectKey2TurnAnim.left >= 109 * 4)
					{
						rectKey2TurnAnim.left = 109 * 4;
					}

					key2Timer = 0;
				}

				// if timer > 0.f et que key1Turn et key1Turn sont true		 ALORS ultime
				// else if timer <= 0.f										 ALORS reset la Key true
				
				if (key1Turn || key2Turn)
				{ 
					keyWaiterTimer -= getDeltaTime();
				}

				if (keyWaiterTimer > 0.f && key1Turn && key2Turn && number == 0)
				{
					// Ulti
					keyStartUlt = true;
					std::cout << "mettre l'Ultime ICI | Fichier UI.cpp, Ligne 294 (mettre un bool pour l'ultime parce que ce IF n'est pas illimité)" << std::endl;
				}
				else if (keyWaiterTimer <= 0.f)
				{

					if (key1Turn)
					{
						key1Turn = false;
						key1Reverse = true;
						key1Disable = true;
					}
					else
					{
						key2Turn = false;
						key2Reverse = true;
						key2Disable = true;
					}
					keyWaiterTimer = 2.f;
				}

				if (!keyStartUlt)
				{




					if (key1Reverse) key1Timer += getDeltaTime();
					if (key2Reverse) key2Timer += getDeltaTime();

					// Key 1 Animation Reverse
					if (key1Reverse && key1Timer > 0.2f)
					{
						spriteKey1.setTexture(textureKeyTurnAnim);
						spriteKey1.setTextureRect(rectKey1TurnAnim);
						rectKey1TurnAnim.left -= 109;
						if (rectKey1TurnAnim.left <= 0)
						{
							rectKey1TurnAnim.left = 0;
							key1Reverse = false;
							key1Echec = true;
						}
						key1Timer = 0;

					}

					// Key 2 Animation Reverse
					if (key2Reverse && key2Timer > 0.2f)
					{
						spriteKey2.setTexture(textureKeyTurnAnim);
						spriteKey2.setTextureRect(rectKey2TurnAnim);

						rectKey2TurnAnim.left -= 109;
						if (rectKey2TurnAnim.left <= 0)
						{
							rectKey2TurnAnim.left = 0;
							key2Reverse = false;
							key2Echec = true;
						}

						key2Timer = 0;
					}

					// Position 
					if (key1Echec)
					{
						spriteKey1.setTexture(textureKey);
						// Key Position Animation
						positionKey1.x -= 2.f;
						if (positionKey1.x <= 240.f)
							positionKey1.x = 240.f;
						spriteKey1.setPosition(positionKey1);

						// Key Rect Animation 
						rectKeyAnim1.width += 2;
						if (rectKeyAnim1.width >= 257)
						{
							rectKeyAnim1.width = 257;
							key1Echec = false;
							key1Ulti = false;

						}
						spriteKey1.setTextureRect(rectKeyAnim1);


					}

					if (key2Echec)
					{
						spriteKey2.setTexture(textureKey);
						// Key Position Animation
						positionKey2.x += 2.f;
						if (positionKey2.x >= 1720.f) 
							positionKey2.x = 1720.f;
						spriteKey2.setPosition(positionKey2);

						// Key Rect Animation
						rectKeyAnim2.width += 2;
						if (rectKeyAnim2.width >= 257)
						{
							rectKeyAnim2.width = 257;
							key2Echec = false;
							key2Ulti = false;
						}
						spriteKey2.setTextureRect(rectKeyAnim2);
					}
				}

				if (key1Disable)
				{
					key1WaiterDisableTimer += getDeltaTime();
				}

				if (key2Disable)
				{
					key2WaiterDisableTimer += getDeltaTime();
				}

				if (key1WaiterDisableTimer > 1.f)
				{
					key1Disable = false;
					key1WaiterDisableTimer = 0.f;
				}

				if (key2WaiterDisableTimer > 1.f)
				{
					key2Disable = false;
					key2WaiterDisableTimer = 0.f;
				}

				if (keyStartUlt)
				{
					keyWaiterUltimeTimer += getDeltaTime();
				}

				if (keyWaiterUltimeTimer > 1.81f)
				{
					keyStartUlt = false;
					keyWaiterUltimeTimer = 0.f;
					number = 101;
					Ultime::SetFirstPass(false);
				}
			}
		}

#pragma endregion

}

#pragma region Getter and Setter

// Getter and Setter keyStartUlt
bool UI::GetKeyStartUlt()
{
	return keyStartUlt;
}

void UI::SetKeyStartUlt(bool _keyStartUlt)
{
	keyStartUlt = _keyStartUlt;
}

#pragma endregion


#pragma region Fonction Public

void UI::Init()
{
	texture.loadFromFile("../Ressources/Textures/Chauffe.png");
	textureTwo.loadFromFile("../Ressources/Textures/Bare.png");
	textureThree.loadFromFile("../Ressources/Textures/Jauge.png");

	// Key Animation
	textureKey.loadFromFile("../Ressources/Textures/clef.png");
	textureKeyTurnAnim.loadFromFile("../Ressources/textures/clef_spritesheet.png");

	spriteKey1.setTexture(textureKey);
	spriteKey2.setTexture(textureKey);

	spriteKey1.setPosition(positionKey1);
	spriteKey2.setPosition(positionKey2);

	spriteKey2.setScale(-1.f, 1.f);
}

void UI::Update(int _playerHP)
{
	//update

	static float time = 0;

	time += getDeltaTime();

	UI::secondNumber = (37 - _playerHP) <= 37 ? (37 - _playerHP) : 37;

	UpdateKeyAnim();

	updateRect();
}

void UI::Display(sf::RenderWindow& _window)
{
	sprite.setPosition(31, 284);
	sprite.setTexture(texture);
	sprite.setOrigin(0, texture.getSize().y);
	sprite.setScale(1, -1);
	_window.draw(sprite);

	sprite.setPosition(1840, 284);
	_window.draw(sprite);

	spriteTwo.setTexture(textureTwo);
	spriteTwo.setPosition(593, 31);
	_window.draw(spriteTwo);

	spriteThree.setTexture(textureThree);
	spriteThree.setTextureRect(sf::IntRect(0, 0, 103, 104));
	spriteThree.setPosition(441, 17);
	_window.draw(spriteThree);
	drawCircle(_window, sf::Vector2f(493, 70), 53, MetalicGrey);

	spriteThree.setPosition(1414, 17);
	_window.draw(spriteThree);
	drawCircle(_window, sf::Vector2f(1465, 70), 53, MetalicGrey);

	if (number == 0)
		spriteThree.setTextureRect(sf::IntRect(104, 0, 110, 110));
	else
		spriteThree.setTextureRect(sf::IntRect(214, 0, 110, 110));
	spriteThree.setPosition(437, 14);
	_window.draw(spriteThree);
	spriteThree.setPosition(1410, 14);
	_window.draw(spriteThree);

	drawQuad(_window, sf::Vector2f(1358, 38), 60, sf::Color::Red);
	drawVerticalRectOne(_window, sf::Vector2f(35, 288), 41, sf::Color::Black);
	drawVerticalRectTwo(_window, sf::Vector2f(1844, 288), 41, sf::Color::Black);


	if (isPowerUpReady && number == 0)
	{
		_window.draw(spriteKey1);
		_window.draw(spriteKey2);
	}
}

void UI::SmallShot()
{
	if (UI::IsOverLoadOne == false)
	{
		IsPlayerOneShooting = true;
		thirdNumberOne--;
		thirdNumberOne--;
		thirdNumberOne--;

		if (thirdNumberOne < -1)
			thirdNumberOne = -1;
	}
}

void UI::BigShot()
{
	if (UI::IsOverLoadTwo == false)
	{
		// Pas mal le troll Hugo Hugo Hugo
		IsPlayerTwoShooting = true;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;
		thirdNumberTwo--;

		if (thirdNumberTwo < -1)
			thirdNumberTwo = -1;
	}
}

bool UI::canSmallShot()
{
	return !UI::IsOverLoadOne;
}

bool UI::canBigShot()
{
	return !UI::IsOverLoadTwo;
}

void UI::KillEnemy()
{
	if (UI::number > 0)
	{
		number--;
	}
}

#pragma endregion
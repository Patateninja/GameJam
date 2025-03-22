#pragma once

/*

namespace test
{
	sf::Color MetalicGrey = sf::Color(63, 63, 63);
	sf::Sprite sprite;
	sf::Sprite spriteTwo;
	sf::Sprite spriteThree;
	sf::RectangleShape rect;
	sf::Texture texture;
	sf::Texture textureTwo;
	sf::Texture textureThree;
	int number = 101;
	bool IsOverLoadOne = false;
	bool IsOverLoadTwo = false;
	bool IsPlayerOneShooting = false;
	bool IsPlayerTwoShooting = false;

	void drawCircle(sf::RenderWindow& window, sf::Vector2f pos, float radius, sf::Color color)
	{
		if (number < 0)
			number = 101;
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


	int secondNumber = 0;

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

	int thirdNumberOne = 251;
	int thirdNumberTwo = 251;

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

	float timerOverLoadOne = 0;
	float timerOverLoadTwo = 0;

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
}



	//init
	test::texture.loadFromFile("../Ressources/Textures/Chauffe.png");
	test::textureTwo.loadFromFile("../Ressources/Textures/Bare.png");
	test::textureThree.loadFromFile("../Ressources/Textures/Jauge.png");



	//update
	static float time = 0;

	time += getDeltaTime();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && time > 0.2)
	{
		test::number--;
		time = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && time > 0.2)
	{
		test::secondNumber++;
		time = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::O) && time > 0.2 && test::IsOverLoadOne == false)
	{
		test::IsPlayerOneShooting = true;
		test::thirdNumberOne--;
		test::thirdNumberOne--;
		test::thirdNumberOne--;

		if (test::thirdNumberOne < -1)
			test::thirdNumberOne = -1;

		time = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && time > 0.2 && test::IsOverLoadTwo == false)
	{
		test::IsPlayerTwoShooting = true;
		test::thirdNumberTwo--;
		test::thirdNumberTwo--;
		test::thirdNumberTwo--;
		test::thirdNumberTwo--;
		test::thirdNumberTwo--;
		test::thirdNumberTwo--;
		test::thirdNumberTwo--;
		test::thirdNumberTwo--;
		test::thirdNumberTwo--;
		test::thirdNumberTwo--;
		test::thirdNumberTwo--;
		test::thirdNumberTwo--;
		test::thirdNumberTwo--;
		test::thirdNumberTwo--;
		test::thirdNumberTwo--;
		test::thirdNumberTwo--;
		test::thirdNumberTwo--;
		test::thirdNumberTwo--;

		if (test::thirdNumberTwo < -1)
			test::thirdNumberTwo = -1;

		time = 0;
	}

	test::updateRect();



	//display 

	test::sprite.setPosition(31, 284);
	test::sprite.setTexture(test::texture);
	test::sprite.setOrigin(0 , test::texture.getSize().y);
	test::sprite.setScale(1, -1);
	_window.draw(test::sprite);

	test::sprite.setPosition(1840, 284);
	_window.draw(test::sprite);

	test::spriteTwo.setTexture(test::textureTwo);
	test::spriteTwo.setPosition(593,31);
	_window.draw(test::spriteTwo);

	test::spriteThree.setTexture(test::textureThree);
	test::spriteThree.setTextureRect(sf::IntRect(0, 0, 103, 104));
	test::spriteThree.setPosition(441,17);
	_window.draw(test::spriteThree);
	test::drawCircle(_window, sf::Vector2f(493, 70), 53, test::MetalicGrey);

	test::spriteThree.setPosition(1414, 17);
	_window.draw(test::spriteThree);
	test::drawCircle(_window, sf::Vector2f(1465, 70), 53, test::MetalicGrey);

	if(test::number == 0)
		test::spriteThree.setTextureRect(sf::IntRect(104, 0, 110, 110));
	else
		test::spriteThree.setTextureRect(sf::IntRect(214, 0, 110, 110));
	test::spriteThree.setPosition(437, 14);
	_window.draw(test::spriteThree);
	test::spriteThree.setPosition(1410, 14);
	_window.draw(test::spriteThree);

	test::drawQuad(_window, sf::Vector2f(1358, 38), 60, sf::Color::Red);
	test::drawVerticalRectOne(_window, sf::Vector2f(35, 288), 41, sf::Color::Black);
	test::drawVerticalRectTwo(_window, sf::Vector2f(1844, 288), 41, sf::Color::Black);
*/
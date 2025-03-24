#include "Keys.hpp"
#include "tools.hpp"

void Keys::updateInteractKey()
{
	isInteractPressed = !isInteractHeld && (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Enter) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Backspace));
	isInteractHeld = (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Enter) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Backspace));


	isUpPressed = !isUpHeld && (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up));
	isUpHeld = (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up));


	isDownPressed = !isDownHeld && (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down));
	isDownHeld = (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down));
}
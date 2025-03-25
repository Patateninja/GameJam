#include "tools.hpp"

bool _isInteractPressed;
bool _isUpPressed;
bool _isDownPressed;
bool _isInteractHeld;
bool _isUpHeld;
bool _isDownHeld;

bool Keys::isInteractPressed() { return _isInteractPressed; }
bool Keys::isUpPressed() { return _isUpPressed; }
bool Keys::isDownPressed() { return _isDownPressed; }

void Keys::updateInteractKey()
{
	_isInteractPressed = !_isInteractHeld && (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Enter) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Backspace));
	_isInteractHeld = (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Enter) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Backspace));


	_isUpPressed = !_isUpHeld && (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up));
	_isUpHeld = (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up));


	_isDownPressed = !_isDownHeld && (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down));
	_isDownHeld = (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down));
}
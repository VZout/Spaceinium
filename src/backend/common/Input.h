/*
 * Input.h
 *
 *  Created on: Jun 3, 2015
 *      Author: bideb
 */

#ifndef BACKEND_INPUT_H_
#define BACKEND_INPUT_H_

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/System/Vector2.hpp>
#include "../../Spaceinium.h"
#include <vector>

namespace sf {
class RenderWindow;
} /* namespace sf */

class Input {
private:
	static sf::Vector2i mousePos;
public:

	Input();
	virtual ~Input();

	static std::vector<sf::Keyboard::Key> heldKeys;
	static std::vector<sf::Keyboard::Key> downKeys;
	static std::vector<sf::Keyboard::Key> upKeys;

	static bool getDown(sf::Keyboard::Key key);
	static bool getHeld(sf::Keyboard::Key key);
	static bool getReleased(sf::Keyboard::Key key);

	static void addDown(sf::Keyboard::Key key);
	static void removeHeld(sf::Keyboard::Key key);
	static void clearInput();

	static void updateMousePos(sf::Vector2i pos);
	static sf::Vector2i getMousePos();
};

#endif /* BACKEND_INPUT_H_ */

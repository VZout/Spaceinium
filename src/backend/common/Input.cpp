/*
 * Input.cpp
 *
 *  Created on: Jun 3, 2015
 *      Author: bideb
 */

#include "Input.h"

#include <algorithm>

sf::Vector2i Input::mousePos;
std::vector<sf::Keyboard::Key> Input::heldKeys;
std::vector<sf::Keyboard::Key> Input::downKeys;
std::vector<sf::Keyboard::Key> Input::upKeys;

Input::Input() {
}

Input::~Input() {
}

bool Input::getDown(sf::Keyboard::Key key) {
	return std::find(downKeys.begin(), downKeys.end(), key) != downKeys.end();
}

bool Input::getHeld(sf::Keyboard::Key key) {
	return std::find(heldKeys.begin(), heldKeys.end(), key) != heldKeys.end();
}

bool Input::getReleased(sf::Keyboard::Key key) {
	return std::find(upKeys.begin(), upKeys.end(), key) != upKeys.end();
}

void Input::addDown(sf::Keyboard::Key key) {
	heldKeys.push_back(key);
	downKeys.push_back(key);
}

void Input::removeHeld(sf::Keyboard::Key key) {
	heldKeys.erase(std::remove(heldKeys.begin(), heldKeys.end(), key), heldKeys.end());
}

void Input::clearInput() {
	downKeys.clear();
	upKeys.clear();
}

void Input::updateMousePos(sf::Vector2i pos) {
	mousePos = pos;
}

sf::Vector2i Input::getMousePos() {
	return mousePos;
}

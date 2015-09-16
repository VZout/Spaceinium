/*
 * Text.cpp
 *
 *  Created on: Jun 3, 2015
 *      Author: bideb
 */

#include "Text.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <iostream>

#include "../../Spaceinium.h"

Text::Text(const char* value, int size, sf::Font& font) {
	this->text = sf::Text(value, font);
	this->text.setPosition(0, 0);
	this->text.setCharacterSize(size);
}

Text::Text(const char* value, int x, int y, int size, sf::Font& font) {
	this->text = sf::Text(value, font);
	this->text.setPosition(x, y);
	this->text.setCharacterSize(size);
}

Text::Text() {
}

Text::~Text() {
}

void Text::render() {
	Spaceinium::window.draw(text);
}

float Text::getWidth() {
	return text.getLocalBounds().width;
}

float Text::getHeight() {
	return text.getLocalBounds().height;
}

void Text::setOrigin(Origin origin) {
	if(origin == LEFT) {
		std::cout << "left" << std::endl;
		text.setOrigin(0, 0);
	}

	else if(origin == RIGHT) {
			std::cout << "Right" << std::endl;
			text.setOrigin(getWidth(), 0);
	}

	else if(origin == CENTER) {
			std::cout << "center" << std::endl;
			text.setOrigin(getWidth() / 2, 0);
	}
}

void Text::setColor(sf::Color color) {
	text.setColor(color);
}

sf::Color Text::getColor() {
	return text.getColor();
}

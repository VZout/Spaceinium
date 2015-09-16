/*
 * TextButton.cpp
 *
 *  Created on: Jun 3, 2015
 *      Author: bideb
 */

#include "TextButton.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "../../Spaceinium.h"
#include "../../Textures.h"

TextButton::TextButton() : InteractableUIElement(0, false, 0) {
	this->text = text;
	normalColor = sf::Color::Cyan;
	selectedColor = sf::Color::Green;

	sprite = AnimatedSprite(0, 0, 1, 1, 2, Textures::get(0));
	sprite.addFrame(0, Textures::get(0));
	sprite.addFrame(0, Textures::get(1));
}

TextButton::TextButton(int id, bool selected, Text text, sf::Color selectedColor, std::function<void()> action) : InteractableUIElement(id, selected, action) {
	this->text = text;
	this->normalColor = text.getColor();
	this->selectedColor = selectedColor;

	sprite = AnimatedSprite(text.text.getPosition().x, text.text.getPosition().y, 3, 1, 2, Textures::get(0));
	sprite.addFrame(0, Textures::get(0));
	sprite.addFrame(0, Textures::get(1));
}

TextButton::~TextButton() {
}

void TextButton::render() {
	text.render();

	if(selected)
		sprite.render();
}

void TextButton::update() {
	sprite.update();

	sprite.setPosition(text.text.getPosition().x - 30, text.text.getPosition().y + 18);

	if(selected) {
		this->text.setColor(selectedColor);
	} else {
		this->text.setColor(normalColor);
	}
}

void TextButton::press() {
	action();
}

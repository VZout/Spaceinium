/*
 * Toggle.cpp
 *
 *  Created on: Jul 17, 2015
 *      Author: bideb
 */

#include "Toggle.h"

#include <SFML/Graphics/Texture.hpp>

#include "../../Textures.h"

Toggle::Toggle() : InteractableUIElement(0, false, 0){
	this->text = text;
	this->normalColor = sf::Color::Cyan;
	this->selectedColor = sf::Color::Green;

	sprite = AnimatedSprite(0, 0, 1, 1, 1, Textures::get(0));
	sprite.addFrame(0, Textures::get(0));
	sprite.addFrame(0, Textures::get(1));

	spriteOn = Sprite(Textures::get(3), 0, 0, 1);
	spriteOff  = Sprite(Textures::get(4), 0, 0, 0.1f);

	value = false;
}

Toggle::Toggle(unsigned int id, bool selected, Text text, sf::Color selectedColor, std::function<void()> action) : InteractableUIElement(id, selected, action) {
	this->text = text;
	this->normalColor = text.getColor();
	this->selectedColor = selectedColor;

	sprite = AnimatedSprite(text.text.getPosition().x, text.text.getPosition().y, 3, 1, 2, Textures::get(0));
	sprite.addFrame(0, Textures::get(0));
	sprite.addFrame(0, Textures::get(1));

	spriteOn = Sprite(Textures::get(3), 0, 0, 2);
	spriteOff  = Sprite(Textures::get(2), 0, 0, 2);

	value = false;
}

Toggle::~Toggle() {
}

void Toggle::render() {
	text.render();

	if(selected)
		sprite.render();

	if(value)
		spriteOn.render();
	else
		spriteOff.render();
}

void Toggle::update() {
	sprite.update();
	spriteOn.update();
	spriteOff.update();

	sprite.setPosition(text.text.getPosition().x - 30, text.text.getPosition().y + 18);
	spriteOn.setPosition(text.text.getPosition().x + text.getWidth() + 15, text.text.getPosition().y + 12);
	spriteOff.setPosition(text.text.getPosition().x + text.getWidth() + 15, text.text.getPosition().y + 12);

	if(selected) {
		this->text.setColor(selectedColor);
		this->spriteOn.setColor(selectedColor);
		this->spriteOff.setColor(selectedColor);
	} else {
		this->text.setColor(normalColor);
		this->spriteOn.setColor(normalColor);
		this->spriteOff.setColor(normalColor);
	}
}

void Toggle::press() {
	action();
}

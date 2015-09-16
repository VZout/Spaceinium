/*
 * Sprite.cpp
 *
 *  Created on: Jun 17, 2015
 *      Author: bideb
 */

#include "Sprite.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

#include "../../Spaceinium.h"
#include "../../Textures.h"

Sprite::Sprite() {
	sprite.setScale(1, 1);
	sprite.setPosition(0, 0);
}

Sprite::Sprite(sf::Texture& texture, float x, float y, float scale) {
	sprite.setTexture(texture);
	sprite.setScale(scale, scale);
	sprite.setPosition(x, y);
}

Sprite::~Sprite() {
}

void Sprite::render() {
	Spaceinium::window.draw(sprite);
}

void Sprite::update() {

}

void Sprite::setPosition(int x, int y) {
	sprite.setPosition(x, y);
}

void Sprite::setRotation(float angle) {
	sprite.setRotation(angle);
}

sf::Vector2f Sprite::getPosition() {
	return sprite.getPosition();
}

void Sprite::setTexture(sf::Texture& texture) {
	sprite.setTexture(texture);
}

void Sprite::setColor(sf::Color color) {
	sprite.setColor(color);
}

void Sprite::setScale(float x, float y) {
	sprite.setScale(x, y);
}

float Sprite::getWidth() {
	return sprite.getTexture()->getSize().x;
} 

float Sprite::getHeight() {
	return sprite.getTexture()->getSize().y;
} 

sf::Texture Sprite::getTexture() {
	return *sprite.getTexture();
}

void Sprite::setOriginToCenter() {
	sprite.setOrigin(getWidth() / 2, getHeight() / 2);
}

void Sprite::setOrigin(float x, float y) {
	sprite.setOrigin(x, y);
}


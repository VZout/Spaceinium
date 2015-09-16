/*
 * Particle.cpp
 *
 *  Created on: Jul 20, 2015
 *      Author: bideb
 */

#include "Particle.h"

Particle::Particle() : GameObject(sf::Vector2f(0, 0)) {
	this->velocity = sf::Vector2f(1, 0);
}

Particle::Particle(Sprite sprite, sf::Vector2f position, sf::Vector2f velocity) : GameObject(position) {
	this->position = position;
	this->velocity = velocity;
	this->sprite = sprite;
	this->sprite.setPosition(position.x, position.y);
}

Particle::~Particle() {
}

void Particle::init() {
}

void Particle::render() {
	sprite.render();
}

void Particle::update() {
	sprite.update();
	sprite.setPosition(position.x, position.y);
	this->position += velocity;
}


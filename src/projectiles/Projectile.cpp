/*
 * Projectile.cpp
 *
 *  Created on: Sep 6, 2015
 *      Author: bideb
 */

#include "Projectile.h"

#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <cmath>

#include "../backend/common/Resources.h"

Projectile::Projectile() {
	speed  = 0;
}

Projectile::Projectile(float speed, sf::Vector2f position, float rotation) {
	this->position = position;
	this->rotation = rotation;
	this->speed = speed;

	friction = 1;
	accelSpeed = 0;
	maxSpeed = 5;
}

Projectile::~Projectile() {
	// TODO Auto-generated constructor stub
}

void Projectile::init(State& state) {
	direction.x = (float) std::cos((rotation * atan(1)*4) / 180);
	direction.y = (float) std::sin((rotation * atan(1)*4) / 180);
	float length = sqrt(std::pow(direction.x, 2) + std::pow(direction.y, 2));
	if (length > 0) {
	    direction.x = direction.x / length;
	    direction.y = direction.y / length;
	}

	acceleration = sf::Vector2f(0, 0);

	velocity = direction * speed;

	sprite = Sprite(Resources::getWeaponTexture(1), position.x, position.y, 2);
	sprite.setOriginToCenter();
	sprite.setRotation(rotation);
}

void Projectile::render() {
	sprite.render();
}

void Projectile::update() {
	handlePhysics();
	sprite.update();
	sprite.setPosition(position.x, position.y);
}


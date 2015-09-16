/*
 * Entity.cpp
 *
 *  Created on: Sep 6, 2015
 *      Author: bideb
 */

#include "Entity.h"

#include <SFML/System/Vector2.hpp>

#include <cmath>

Entity::Entity() {
	this->state = 0;
	friction = 0;
	accelSpeed = 0;
	maxSpeed = 0;
	rotation = 0;
	state = 0;
}

Entity::~Entity() {
	// TODO Auto-generated destructor stub
}

void Entity::init(State* state) {
	this->state = state;
}

void Entity::render() {

}

void Entity::update() {

}

void Entity::handlePhysics() {
	velocity += acceleration;

	float length = std::sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y));
	sf::Vector2f normalized = sf::Vector2f(velocity.x / length, velocity.y / length);
	//Clamp Velocity
	if(length > maxSpeed) {
		velocity.x = normalized.x * maxSpeed;
		velocity.y = normalized.y * maxSpeed;
	}

	position += velocity;

	if(acceleration.x == 0 && acceleration.y == 0)
		velocity *= friction;

	if(velocity.x > 0 && velocity.x < 0.1) {
		velocity.x = 0;
	}

	if(velocity.y > 0 && velocity.y < 0.1) {
		velocity.y = 0;
	}
}


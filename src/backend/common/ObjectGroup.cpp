/*
 * ObjectGroup.cpp
 *
 *  Created on: Jun 9, 2015
 *      Author: bideb
 */

#include "ObjectGroup.h"

ObjectGroup::ObjectGroup() {
	this->position = sf::Vector2f(0,0);
	this->targetPosition = this->position;
	speed = 1;
}

ObjectGroup::ObjectGroup(sf::Vector2f position) {
	this->position = position;
	this->targetPosition = this->position;
	speed = 1;
}

ObjectGroup::~ObjectGroup() {
}

void ObjectGroup::init() {

}

void ObjectGroup::render() {

}

void ObjectGroup::update() {
	if(position != targetPosition) {
		if(position.x < targetPosition.x) {
			position.x += speed;
		} else if(position.x > targetPosition.x) {
			position.x -= speed;
		}

		if(position.y < targetPosition.y) {
			position.y += speed;
		} else if(position.y > targetPosition.y) {
			position.y -= speed;
		}
	}
}

void ObjectGroup::moveToPos(sf::Vector2f target, float speed) {
	this->targetPosition = target;
	this->speed = speed;
}

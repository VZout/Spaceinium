/*
 * GameObject.cpp
 *
 *  Created on: Jul 20, 2015
 *      Author: bideb
 */

#include "GameObject.h"

GameObject::GameObject() {
	this->position = sf::Vector2f(0, 0);
}

GameObject::GameObject(sf::Vector2f position) {
	this->position = position;
}

GameObject::~GameObject() {
}

void GameObject::init() {

}

void GameObject::render() {

}

void GameObject::update() {

}



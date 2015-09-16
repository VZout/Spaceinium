/*
 * State.cpp
 *
 *  Created on: May 31, 2015
 *      Author: bideb
 */

#include "State.h"
#include "iostream"

#include "../../Spaceinium.h"

State::State() {
}

State::~State() {
}

void State::draw(sf::Drawable& drawable) {
	Spaceinium::window.draw(drawable);
}

void State::render() {
	for(unsigned int i = 0; i < bullets.size(); i++) {
		bullets[i]->render();
	}
}

void State::update() {
	for(unsigned int i = 0; i < bullets.size(); i++) {
		bullets[i]->update();
	}
}

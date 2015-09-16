/*
 * OptionsMenuGroup.cpp
 *
 *  Created on: Jul 16, 2015
 *      Author: bideb
 */

#include "OptionsMenuGroup.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <functional>
#include <iostream>

#include "../backend/common/Input.h"
#include "../backend/common/Resources.h"
#include "../states/MenuState.h"
#include "../Spaceinium.h"

OptionsMenuGroup::OptionsMenuGroup() : ObjectGroup(sf::Vector2f(0,0)) {
	this->parent = 0;
}

OptionsMenuGroup::OptionsMenuGroup(sf::Vector2f pos, MenuState* parent) : ObjectGroup(pos) {
	this->parent = parent;

}

OptionsMenuGroup::~OptionsMenuGroup() {
}

void OptionsMenuGroup::init() {
	backText = Text("Back", 30, Resources::mainFont);
	backText.setColor(sf::Color(255, 255, 255, 175));

	fullscreenText = Text("Fullscreen", 30, Resources::mainFont);
	fullscreenText.setColor(sf::Color(255, 255, 255, 175));

	fullscreenToggle = Toggle(0, false, fullscreenText, sf::Color::White,
			std::bind(&OptionsMenuGroup::fullscreenAction, this));
	backButton = TextButton(1, false, backText, sf::Color::White,
			std::bind(&OptionsMenuGroup::backAction, this));

	buttonlist.add(&fullscreenToggle);
	buttonlist.add(&backButton);
	buttonlist.setActive(false);
}

void OptionsMenuGroup::render() {
	buttonlist.render();
}

void OptionsMenuGroup::update() {
	ObjectGroup::update();
	buttonlist.update();

	fullscreenToggle.text.text.setPosition(sf::Vector2f(50,20) + position);
	backButton.text.text.setPosition(sf::Vector2f(50, 200) + position);

	if(Input::getDown(sf::Keyboard::S) || Input::getDown(sf::Keyboard::Down))
		buttonlist.next();

	if(Input::getDown(sf::Keyboard::W) || Input::getDown(sf::Keyboard::Up))
		buttonlist.prev();

	if(this->targetPosition == this->position) {
	if(Input::getDown(sf::Keyboard::Return) || Input::getDown(sf::Keyboard::Space))
		buttonlist.press();
	}
}

void OptionsMenuGroup::fullscreenAction() {
	std::cout << "Toggle Fullscreen" << std::endl;
	fullscreenToggle.value = !fullscreenToggle.value;
	Spaceinium::toggleFullscreen();
}

void OptionsMenuGroup::backAction() {
	std::cout << "Back" << std::endl;
	buttonlist.setActive(false);
	parent->mainGroup.buttonlist.setActive(true);
	parent->mainGroup.moveToPos(sf::Vector2f(0, 0), 5);
	this->moveToPos(sf::Vector2f(-280, 0), 10);
}

/*
 * StartMenuGroup.cpp
 *
 *  Created on: Jun 9, 2015
 *      Author: bideb
 */

#include "StartMenuGroup.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <functional>
#include <iostream>

#include "../backend/common/Input.h"
#include "../backend/common/Resources.h"
#include "../states/GameState.h"
#include "../states/MenuState.h"
#include "../Spaceinium.h"

StartMenuGroup::StartMenuGroup() : ObjectGroup(sf::Vector2f(0,0)) {
	this->parent = 0;
}

StartMenuGroup::StartMenuGroup(sf::Vector2f pos, MenuState* parent) : ObjectGroup(pos) {
	this->parent = parent;
}

StartMenuGroup::~StartMenuGroup() {
}

void playAction() {
	std::cout << "Play Game" << std::endl;
	Spaceinium::switchState(new GameState());
}

void StartMenuGroup::optionsAction() {
	std::cout << "Options" << std::endl;
	buttonlist.setActive(false);
	parent->optionsGroup.buttonlist.setActive(true);
	parent->optionsGroup.moveToPos(sf::Vector2f(0, 0), 10);
	this->moveToPos(sf::Vector2f(0, -110), 5);
}

void quitAction() {
	Spaceinium::window.close();
}

void StartMenuGroup::init() {
	playText = Text("Play", 30, Resources::mainFont);
	playText.setColor(sf::Color(255, 255, 255, 175));
	optionsText = Text("Options", 30, Resources::mainFont);
	optionsText.setColor(sf::Color(255, 255, 255, 175));
	quitText = Text("Quit", 30, Resources::mainFont);
	quitText.setColor(sf::Color(255, 255, 255, 175));

	playButton = TextButton(0, true, playText, sf::Color::White, std::bind(playAction));
	optionsButton = TextButton(1, false, optionsText, sf::Color::White, std::bind(&StartMenuGroup::optionsAction, this));
	quitButton = TextButton(2, false, quitText, sf::Color::White, std::bind(quitAction));

	buttonlist.add(&playButton);
	buttonlist.add(&optionsButton);
	buttonlist.add(&quitButton);
}

void StartMenuGroup::render() {
	buttonlist.render();
}

void StartMenuGroup::update() {
	ObjectGroup::update();
	buttonlist.update();

	playButton.text.text.setPosition(50 + position.x, 10 + position.y);
	optionsButton.text.text.setPosition(50 + position.x, 40 + position.y);
	quitButton.text.text.setPosition(50 + position.x, 70 + position.y);

	if(Input::getDown(sf::Keyboard::S) || Input::getDown(sf::Keyboard::Down))
		buttonlist.next();

	if(Input::getDown(sf::Keyboard::W) || Input::getDown(sf::Keyboard::Up))
		buttonlist.prev();

	if(Input::getDown(sf::Keyboard::Return) || Input::getDown(sf::Keyboard::Space))
		buttonlist.press();
}

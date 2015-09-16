/*
 * MenuState.cpp
 *
 *  Created on: May 31, 2015
 *      Author: Viktor Zoutman
 */

#include "MenuState.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <string>

#include "../backend/gui/Text.h"
#include "../Spaceinium.h"
#include "../Textures.h"

MenuState::MenuState() {
	particleTimer = 0;
	delay = 4;
}

MenuState::~MenuState() {
}

void MenuState::load() {
}

void MenuState::init() {

	mainGroup = StartMenuGroup(sf::Vector2f(0,0), this);
	optionsGroup = OptionsMenuGroup(sf::Vector2f(-280, 0), this);

	mainGroup.init();
	optionsGroup.init();

	particleSprite.setTexture(Textures::get(0));

	for(unsigned int i = 0; i < 220; i++) {
		particleSprite.setColor(sf::Color(255,255,255,randomFloatRange(120, 230)));
		float scale = randomFloatRange(0.5, 2.0);
		particleSprite.setScale(scale, scale);
		particles.push_back(Particle(particleSprite, 
					sf::Vector2f(randomFloatRange(0,1280), 
					randomFloatRange(0,720)), 
					sf::Vector2f(-randomFloatRange(0.1, 1), 0)));
	}

    if(!music.openFromFile("res/Audio/Music/8_bit_Leaving_Earth.wav"))
    	std::cerr << "Could not load menu music" << std::endl;
    music.play();

}

void MenuState::render() {
	for(unsigned int i = 0; i < particles.size(); i++)
		particles[i].render();

	mainGroup.render();
	optionsGroup.render();
}

void MenuState::update() {
	for(unsigned int i = 0; i < particles.size(); i++)
		particles[i].update();

	mainGroup.update();
	optionsGroup.update();

	for(unsigned int i = 0; i < particles.size(); i++) {
		if(particles[i].position.x <= -10) {
			particles.erase(particles.begin() + (i));
		}
	}

	std::string pc = "Partical Count: " + to_string(particles.size());
	Spaceinium::debugText[1].text.setString(pc);

	if(particleTimer >= delay) {
		particleSprite.setColor(sf::Color(255,255,255,randomFloatRange(120, 230)));
		float scale = randomFloatRange(0.5, 2.0);
		particleSprite.setScale(scale, scale);
	    particles.push_back(Particle(particleSprite, 
					sf::Vector2f(randomFloatRange(1280, 1280), 
					randomFloatRange(0,720)),
					sf::Vector2f(-randomFloatRange(0.1, 1), 0)));
	    particleTimer = 0;
	}

	particleTimer++;
}

void MenuState::onExit() {
	music.~Music();
}

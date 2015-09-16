/*
 * AnimatedSprite.cpp
 *
 *  Created on: Jun 17, 2015
 *      Author: bideb
 */

#include "AnimatedSprite.h"

#include <SFML/Graphics/Texture.hpp>
#include <iostream>

#include "../../Textures.h"

AnimatedSprite::AnimatedSprite() {
	currentState = 0;
	currentTextureID = 0;
	timer = 0;
	time = 10;
}

AnimatedSprite::AnimatedSprite(int x, int y, float scale, int stateAmount, float time, sf::Texture& beginTexture) {
	currentState = 0;
	currentTextureID = 0;
	currentSprite = Sprite(beginTexture, x, y, scale);
	std::vector<sf::Texture> t;
	listOfFrameList.push_back(t);
	timer = 0;
	this->time = time;
}

AnimatedSprite::~AnimatedSprite() {
}

void AnimatedSprite::addFrame(int state, sf::Texture& texture) {
	listOfFrameList.at(state).push_back(texture);
}

void AnimatedSprite::setState(int state) {
	currentState = state;
}

void AnimatedSprite::render() {
	if(!listOfFrameList.at(currentState).empty())
		currentSprite.render();
}

void AnimatedSprite::update() {
	timer += 0.1;
	currentSprite.update();

	if(!listOfFrameList.at(currentState).empty())
		currentSprite.setTexture(listOfFrameList.at(currentState).at(currentTextureID));

	if(timer > time) {
		timer = 0;
		if(currentTextureID < listOfFrameList.at(currentState).size() - 1) {
			currentTextureID++;
		} else {
			currentTextureID--;
		}
	}
}

void AnimatedSprite::setPosition(float x, float y) {
	currentSprite.setPosition(x, y);
}

void AnimatedSprite::setScale(float x, float y) {
	currentSprite.setScale(x, y);
}

Sprite& AnimatedSprite::getSprite() {
	return currentSprite;
}

/*
 * Preferences.cpp
 *
 *  Created on: May 31, 2015
 *      Author: bideb
 */

#include "Preferences.h"

sf::VideoMode Preferences::windowedVideoMode = sf::VideoMode(1280, 720);
sf::VideoMode Preferences::fullscreenVideoMode = sf::VideoMode::getFullscreenModes()[0];

void Preferences::init() {

	//TODO try to load text file and if fails do:
	windowedVideoMode = sf::VideoMode(1280, 720);
	fullscreenVideoMode = sf::VideoMode::getFullscreenModes()[0];

}

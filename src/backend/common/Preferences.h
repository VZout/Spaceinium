/*
 * Preferences.h
 *
 *  Created on: May 31, 2015
 *      Author: bideb
 */

#ifndef PREFERENCES_H_
#define PREFERENCES_H_

#include <SFML/Window/VideoMode.hpp>

class Preferences {
public:
	static sf::VideoMode windowedVideoMode;
	static sf::VideoMode fullscreenVideoMode;
	static void init();
};

#endif /* PREFERENCES_H_ */

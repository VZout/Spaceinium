/*
 * Spaceinium.h
 *
 *  Created on: May 31, 2015
 *      Author: bideb
 */

#ifndef SPACEINIUM_H_
#define SPACEINIUM_H_

#include <sstream>
#include <string>
#include <vector>

#include "backend/gui/Text.h"

namespace sf {
class RenderWindow;
class VideoMode;
class View;
} /* namespace sf */

class State;

class Spaceinium {
private:
	static bool fullscreen;

	static void createWindow(sf::VideoMode vidmode, bool fullscreen);
	sf::View getViewportBox(sf::View view, int windowWidth, int windowHeight);
public:
	Spaceinium();
	static State* currentState;
	virtual ~Spaceinium();

	static sf::RenderWindow window;
	static std::vector<Text> debugText;

	void load();
	void init();
	void render();
	void update();
	static void switchState(State* state);
	static void toggleFullscreen();
};

template <typename T>
std::string to_string ( T Number ) {
 std::ostringstream ss;
 ss << Number;
 return ss.str();
}

#endif /* SPACEINIUM_H_ */

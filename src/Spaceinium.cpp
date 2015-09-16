/*
 * Spaceinium.cpp
 *
 *  Created on: May 31, 2015
 *      Author: Viktor Zoutman
 */

#include "Spaceinium.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <sstream>
#include <string>
#include <vector>

#include "backend/common/Input.h"
#include "backend/common/Preferences.h"
#include "backend/common/Resources.h"
#include "states/MenuState.h"
#include "Textures.h"

bool Spaceinium::fullscreen;
State* Spaceinium::currentState;

sf::RenderWindow Spaceinium::window;
std::vector<Text> Spaceinium::debugText;

Spaceinium::Spaceinium() {
	Preferences::init();

	createWindow(Preferences::windowedVideoMode, false);
	load();
	init();

	currentState = NULL;
	switchState(new MenuState());

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
				toggleFullscreen();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();

			if (event.type == sf::Event::KeyPressed) {
				Input::addDown(event.key.code);
			}

			if (event.type == sf::Event::KeyReleased) {
				Input::removeHeld(event.key.code);
			}

			if (event.type == sf::Event::Resized)
				window.setView(
						getViewportBox(window.getView(), event.size.width,
								event.size.height));

			if (event.type == sf::Event::Closed)
				window.close();
		}

		Input::updateMousePos(sf::Mouse::getPosition(Spaceinium::window));

		render();
		window.display();
		update();

		Input::clearInput();
	}
}

Spaceinium::~Spaceinium() {
	currentState->onExit();
}

void Spaceinium::createWindow(sf::VideoMode vidmode, bool fullscreen) {
	if (fullscreen) {
		window.create(vidmode, "Spaceinium", sf::Style::Fullscreen);
		fullscreen = true;
	} else {
		window.create(vidmode, "Spaceinium", sf::Style::Default);
		fullscreen = false;
	}

	window.setVerticalSyncEnabled(true);
}

sf::View Spaceinium::getViewportBox(sf::View view, int windowWidth,
		int windowHeight) {

	float windowRatio = windowWidth / (float) windowHeight;
	float viewRatio = 1.77777777778;
	float sizeX = 1;
	float sizeY = 1;
	float posX = 0;
	float posY = 0;

	bool horizontalSpacing = true;
	if (windowRatio < viewRatio)
		horizontalSpacing = false;

	if (horizontalSpacing) {
		sizeX = viewRatio / windowRatio;
		posX = (1 - sizeX) / 2.0;
	}

	else {
		sizeY = windowRatio / viewRatio;
		posY = (1 - sizeY) / 2.0;
	}

	view.setViewport(sf::FloatRect(posX, posY, sizeX, sizeY));

	return view;
}

void Spaceinium::load() {
	Resources::loadImportantAssets();

	Textures::add("res/button_marker.png");
	Textures::add("res/button_marker1.png");
	Textures::add("res/textures/gui/toggle_off.png");
	Textures::add("res/textures/gui/toggle_on.png");

	Resources::loadCharacterImage("res/textures/characters/jonas.png");

	Resources::loadWeaponTexture("res/textures/weapons/ak47.png");
	Resources::loadWeaponTexture("res/textures/projectiles/bullet.png");

	Textures::load();
}

void Spaceinium::init() {
	std::string fps = "FPS: Unknown";
	std::string aa = "Anti Aliasing: "
			+ to_string(window.getSettings().antialiasingLevel);
	std::string db = "DepthBits: " + to_string(window.getSettings().depthBits);
	std::string sb = "Stencil Bits: "
			+ to_string(window.getSettings().stencilBits);
	std::string miv = "Minor Version: "
			+ to_string(window.getSettings().minorVersion);
	std::string mav = "Mayor Version: "
			+ to_string(window.getSettings().majorVersion);
	debugText.push_back(Text(fps.c_str(), 15, Resources::mainFont));
	debugText.push_back(Text("Particle Count:", 15, Resources::mainFont));
	debugText.push_back(Text(aa.c_str(), 15, Resources::mainFont));
	debugText.push_back(Text(db.c_str(), 15, Resources::mainFont));
	debugText.push_back(Text(sb.c_str(), 15, Resources::mainFont));
	debugText.push_back(Text(miv.c_str(), 15, Resources::mainFont));
	debugText.push_back(Text(mav.c_str(), 15, Resources::mainFont));
}

void Spaceinium::render() {
	window.clear(sf::Color(3, 3, 28, 255));
	currentState->render();

	for (unsigned int i = 0; i < debugText.size(); i++) {
		debugText[i].text.setPosition(1280 - debugText[i].getWidth() - 5,
				5 + (10 * i));
		debugText[i].render();
	}
}

void Spaceinium::update() {
	currentState->update();
}

void Spaceinium::switchState(State* state) {
	if (currentState != NULL)
		currentState->onExit();

	currentState = state;
	state->load();
	state->init();
}

void Spaceinium::toggleFullscreen() {
	if (fullscreen)
		Spaceinium::createWindow(Preferences::windowedVideoMode, !fullscreen);
	else
		Spaceinium::createWindow(Preferences::fullscreenVideoMode, !fullscreen);

	fullscreen = !fullscreen;
}


/*
 * GameState.cpp
 *
 *  Created on: Jul 20, 2015
 *      Author: bideb
 */

#include "GameState.h"

#include "../backend/common/Resources.h"

GameState::GameState() {
}

GameState::~GameState() {
	// TODO Auto-generated destructor stub
}

void GameState::load() {
}

void GameState::init() {
	int min = 0;
	int max = 2;

	Resources::loadTileTexture("res/textures/tiles/0.png");
	Resources::loadTileTexture("res/textures/tiles/1.png");
	map.loadMap( min + (rand() % (int)(max - min + 1)));
	map.createMap();

	player = Player(sf::Vector2f(200, 200));
	player.init(this);
}

void GameState::render() {

	map.render();
	player.render();
	State::render();
}

void GameState::update() {
	player.update();
	State::update();
}

void GameState::onExit() {

}


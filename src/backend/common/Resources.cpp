/*
 * Resources.cpp
 *
 *  Created on: May 31, 2015
 *      Author: bideb
 */

#include "Resources.h"

#include <SFML/Graphics/Font.hpp>
#include <iostream>

sf::Font Resources::mainFont;
std::vector<sf::Music> Resources::music;
std::vector<sf::Texture> Resources::tileTextures;
std::vector<sf::Texture> Resources::weaponTextures;
std::vector<sf::Image> Resources::characterTextures;

void Resources::loadImportantAssets() {
	if (!mainFont.loadFromFile("res/font/space.ttf")) {
		std::cerr << "Error loading texture" << std::endl;
	}
	((sf::Texture&)mainFont.getTexture(30)).setSmooth(false);
}

void Resources::loadMusicFile(std::string path) {
}

void Resources::loadTileTexture(std::string path) {
	sf::Texture texture;
	if (!texture.loadFromFile(path)) {
		// error...
	} else {
		texture.setSmooth(false);
		tileTextures.push_back(texture);
	}
}

void Resources::loadWeaponTexture(std::string path) {
	sf::Texture texture;
	if (!texture.loadFromFile(path)) {
		// error...
	} else {
		texture.setSmooth(false);
		weaponTextures.push_back(texture);
	}
}

void Resources::loadCharacterImage(std::string path) {
	std::cout << "Loaded character: " << path << std::endl;
	sf::Image texture;
	if (!texture.loadFromFile(path)) {
		// error...
	} else {
		characterTextures.push_back(texture);
	}
}

sf::Texture& Resources::getTileTexture(int index) {
	return tileTextures[index];
}

sf::Texture& Resources::getWeaponTexture(int index) {
	return weaponTextures[index];
}

sf::Image& Resources::getCharacterImage(int index) {
	return characterTextures[index];
}

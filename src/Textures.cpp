/*
 * Textures.cpp
 *
 *  Created on: Jun 15, 2015
 *      Author: bideb
 */

#include "Textures.h"

std::vector<const char*> Textures::texturePaths;
std::vector<sf::Texture> Textures::textures;

Textures::Textures() {
}

Textures::~Textures() {
}

void Textures::load() {
	for(unsigned int i = 0; i < texturePaths.size(); i++) {
		sf::Texture texture;
		if (!texture.loadFromFile(texturePaths[i])) {
		    // error...
		} else {
			texture.setSmooth(false);
			textures.push_back(texture);
		}
	}
}

void Textures::add(const char* path) {
	texturePaths.push_back(path);
}

sf::Texture& Textures::get(int id) {
	return textures[id];
}

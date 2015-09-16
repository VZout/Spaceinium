/*
 * Tile.cpp
 *
 *  Created on: Jul 27, 2015
 *      Author: bideb
 */

#include "Tile.h"

#include "Resources.h"

Tile::Tile() {
	x = 0;
	y = 0;
	size = 32;
	sprite = Sprite(Resources::getTileTexture(0), x, y, 1);

}

Tile::Tile(int type, int x, int y, int size) {
	this->x = x;
	this->y = y;
	this->size = size;

	switch(type) {
	case 0:  sprite = Sprite(Resources::getTileTexture(0), x, y, 1);
		break;
	case 1:  sprite = Sprite(Resources::getTileTexture(1), x, y, 1);
		break;
	}

	this->sprite.setScale((float)size / (float)32, (float)size / (float)32);

}

Tile::~Tile() {
	// TODO Auto-generated destructor stub
}

void Tile::render() {
	sprite.render();
}


/*
 * Tile.h
 *
 *  Created on: Jul 27, 2015
 *      Author: bideb
 */

#ifndef BACKEND_COMMON_TILE_H_
#define BACKEND_COMMON_TILE_H_

#include "../graphics/Sprite.h"

class Tile {
public:
	int x, y;
	int size;
	Sprite sprite;
	Tile();
	Tile(int type, int x, int y, int size);
	virtual ~Tile();

	void render();
};

#endif /* BACKEND_COMMON_TILE_H_ */

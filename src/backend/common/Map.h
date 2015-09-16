/*
 * Map.h
 *
 *  Created on: Jul 27, 2015
 *      Author: bideb
 */

#ifndef BACKEND_COMMON_MAP_H_
#define BACKEND_COMMON_MAP_H_

#include <vector>

#include "Tile.h"

class Map {
public:
	Map();
	virtual ~Map();

	int tileSize;

	unsigned int mapWidth, mapHeight;
	std::vector< std::vector<int> > mapMatrix;

	std::vector<Tile> tiles;

	void loadMap(int id);
	void createMap();
	void render();
};

#endif /* BACKEND_COMMON_MAP_H_ */

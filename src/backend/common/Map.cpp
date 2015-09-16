/*
 * Map.cpp
 *
 *  Created on: Jul 27, 2015
 *      Author: bideb
 */

#include "Map.h"

#include <fstream>
#include <iostream>
#include <string>

#include "../../Spaceinium.h"

Map::Map() {
	std::cout << "New 8x8 map created" << std::endl;
	mapWidth = 8;
	mapHeight = 8;
	std::vector< std::vector<int> > temp(mapWidth, std::vector<int>(mapHeight));
	mapMatrix = temp;
	tileSize = 720/8;
}

Map::~Map() {
	// TODO Auto-generated destructor stub
}

void Map::loadMap(int id) {
	std::cout << "Reading map with id: " << id << std::endl;
	std::string path = "res/maps/map" + to_string(id) + ".txt";
	std::ifstream file(path);

	if(file.is_open()) {
		for (unsigned int h = 0; h < mapHeight; h++) {
			for(unsigned int w = 0; w < mapWidth; w++) {
				mapMatrix[w][h] = 0;
				file >> mapMatrix[w][h];
			}
		}
	}
}

void Map::createMap() {
	for (unsigned int h = 0; h < mapHeight; h++) {
		for(unsigned int w = 0; w < mapWidth; w++) {
			switch(mapMatrix[w][h]) {
				case 0: tiles.push_back(Tile(0, tileSize * w, tileSize * h, tileSize));
				break;
				case 1: tiles.push_back(Tile(1, tileSize * w, tileSize * h, tileSize));
				break;
			}
		}
	}
}

void Map::render() {
	for(unsigned int i = 0; i < tiles.size(); i++)
		tiles[i].render();
}



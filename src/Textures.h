/*
 * Textures.h
 *
 *  Created on: Jun 15, 2015
 *      Author: bideb
 */

#ifndef TEXTURES_H_
#define TEXTURES_H_

#include <SFML/Graphics/Texture.hpp>
#include <vector>

class Textures {
private:
	static std::vector<const char*> texturePaths;
	static std::vector<sf::Texture> textures;
public:
	Textures();
	virtual ~Textures();
	static void load();
	static void add(const char* path);
	static sf::Texture& get(int id);
};

#endif /* TEXTURES_H_ */

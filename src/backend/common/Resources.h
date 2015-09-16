/*
 * Resources.h
 *
 *  Created on: May 31, 2015
 *      Author: bideb
 */

#ifndef BACKEND_RESOURCES_H_
#define BACKEND_RESOURCES_H_

#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>
#include <vector>

namespace sf {
class Font;
} /* namespace sf */

class Resources {
public:
	static void loadImportantAssets();
	static void loadMusicFile(std::string path);
	static void loadTileTexture(std::string path);
	static void loadCharacterImage(std::string path);
	static void loadWeaponTexture(std::string path);

	static sf::Font mainFont;

	static std::vector<sf::Music> music;
	static std::vector<sf::Texture> tileTextures;
	static std::vector<sf::Texture> weaponTextures;
	static std::vector<sf::Image> characterTextures;

	static sf::Texture& getTileTexture(int index);
	static sf::Texture& getWeaponTexture(int index);
	static sf::Image& getCharacterImage(int index);
};

#endif /* BACKEND_RESOURCES_H_ */

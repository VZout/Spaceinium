/*
 * Sprite.h
 *
 *  Created on: Jun 17, 2015
 *      Author: bideb
 */

#ifndef BACKEND_GRAPHICS_SPRITE_H_
#define BACKEND_GRAPHICS_SPRITE_H_

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>

class Sprite {
public:
	sf::Sprite sprite;
	Sprite();
	Sprite(sf::Texture& texture, float x, float y, float scale);
	virtual ~Sprite();
	void render();
	void update();
	void setPosition(int x, int y);
	void setRotation(float angle);
	sf::Vector2f getPosition();
	void setTexture(sf::Texture& texture);
	void setColor(sf::Color color);
	void setScale(float x, float y);
	float getWidth();
	float getHeight();
	sf::Texture getTexture();
	void setOriginToCenter();
	void setOrigin(float x, float y);
};

#endif /* BACKEND_GRAPHICS_SPRITE_H_ */

/*
 * AnimatedSprite.h
 *
 *  Created on: Jun 17, 2015
 *      Author: bideb
 */

#ifndef BACKEND_GRAPHICS_ANIMATEDSPRITE_H_
#define BACKEND_GRAPHICS_ANIMATEDSPRITE_H_

#include <vector>

#include "Sprite.h"

class AnimatedSprite {
private:
	unsigned int currentState;
	unsigned int currentTextureID;
	Sprite currentSprite;
	std::vector<std::vector<sf::Texture>> listOfFrameList;
	float timer;
	float time;
public:
	AnimatedSprite();
	AnimatedSprite(int x, int y, float scale, int stateAmount, float time, sf::Texture& beginTexture);
	virtual ~AnimatedSprite();

	void setStateAnount(int state);
	void addFrame(int state, sf::Texture& texture);
	void setSpeed(float speed);
	void setState(int state);
	void setPosition(float x, float y);
	void setScale(float x, float y);
	void render();
	void update();
	Sprite& getSprite();
};

#endif /* BACKEND_GRAPHICS_ANIMATEDSPRITE_H_ */

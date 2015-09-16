/*
 * Player.h
 *
 *  Created on: Jul 28, 2015
 *      Author: bideb
 */

#ifndef CHARACTERS_PLAYER_H_
#define CHARACTERS_PLAYER_H_

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

#include "../graphics/AnimatedSprite.h"
#include "../graphics/Sprite.h"
#include "Entity.h"
#include "../common/State.h"

class Player : public Entity {
public:
	AnimatedSprite sprite;
	Sprite weaponSprite;

	sf::Image spritesheet;

	sf::Texture walk0;
	sf::Texture walk1;

	float weaponRotation;

	Player();
	Player(sf::Vector2f position);
	virtual ~Player();

	void init(State* state);
	void render();
	void update();
	void handleInput();
	void rotateWeaponTowardsMouse();
	void fire();
};

#endif /* CHARACTERS_PLAYER_H_ */

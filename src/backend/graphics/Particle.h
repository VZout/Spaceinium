/*
 * Particle.h
 *
 *  Created on: Jul 20, 2015
 *      Author: bideb
 */

#ifndef BACKEND_GRAPHICS_PARTICLE_H_
#define BACKEND_GRAPHICS_PARTICLE_H_

#include <SFML/System/Vector2.hpp>

#include "../common/GameObject.h"
#include "../graphics/Sprite.h"

class Particle : public GameObject {
public:
	sf::Vector2f velocity;
	Sprite sprite;

	Particle();
	Particle(Sprite sprite, sf::Vector2f position, sf::Vector2f velocity);
	virtual ~Particle();
	virtual void init();
	virtual void render();
	virtual void update();
};

#endif /* BACKEND_GRAPHICS_PARTICLE_H_ */

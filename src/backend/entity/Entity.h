/*
 * Entity.h
 *
 *  Created on: Sep 6, 2015
 *      Author: bideb
 */

#ifndef SRC_BACKEND_ENTITY_ENTITY_H_
#define SRC_BACKEND_ENTITY_ENTITY_H_

#include <SFML/System/Vector2.hpp>

class State;

class Entity {
protected:
	State* state;
public:
	Entity();
	virtual ~Entity();

	virtual void init(State* state);
	virtual void render();
	virtual void update();
	void handlePhysics();

	sf::Vector2f position;
	sf::Vector2f acceleration;
	sf::Vector2f velocity;

	float friction;
	float accelSpeed;
	float maxSpeed;
	float rotation;
};

#endif /* SRC_BACKEND_ENTITY_ENTITY_H_ */

/*
 * GameObject.h
 *
 *  Created on: Jul 20, 2015
 *      Author: bideb
 */

#ifndef BACKEND_COMMON_GAMEOBJECT_H_
#define BACKEND_COMMON_GAMEOBJECT_H_

#include <SFML/System/Vector2.hpp>

class GameObject {
public:
	sf::Vector2f position;
	GameObject();
	GameObject(sf::Vector2f position);
	virtual ~GameObject();
	virtual void init() = 0;
	virtual void render() = 0;
	virtual void update() = 0;
};

#endif /* BACKEND_COMMON_GAMEOBJECT_H_ */

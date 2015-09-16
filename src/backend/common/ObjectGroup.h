/*
 * ObjectGroup.h
 *
 *  Created on: Jun 9, 2015
 *      Author: bideb
 */

#ifndef BACKEND_OBJECTGROUP_H_
#define BACKEND_OBJECTGROUP_H_

#include <SFML/System/Vector2.hpp>

class ObjectGroup {
private:
	float speed;
public:
	sf::Vector2f targetPosition;
	sf::Vector2f position;
	ObjectGroup();
	ObjectGroup(sf::Vector2f position);
	virtual ~ObjectGroup();

	virtual void init() = 0;
	virtual void render() = 0;
	virtual void update() = 0;

	void moveToPos(sf::Vector2f target, float speed);
};

#endif /* BACKEND_OBJECTGROUP_H_ */

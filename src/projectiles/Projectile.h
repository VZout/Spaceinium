/*
 * Projectile.h
 *
 *  Created on: Sep 6, 2015
 *      Author: bideb
 */

#ifndef SRC_BACKEND_ENTITY_PROJECTILE_H_
#define SRC_BACKEND_ENTITY_PROJECTILE_H_

#include "../backend/entity/Entity.h"
#include "../backend/graphics/Sprite.h"

class Projectile : public Entity {
public:
	Projectile();
	Projectile(float speed, sf::Vector2f position, float rotation);
	virtual ~Projectile();

	void init(State& state);
	void render();
	void update();

	Sprite sprite;
	sf::Vector2f direction;
	float speed;
};

#endif /* SRC_BACKEND_ENTITY_PROJECTILE_H_ */

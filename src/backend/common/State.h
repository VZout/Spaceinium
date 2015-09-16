/*
 * State.h
 *
 *  Created on: May 31, 2015
 *      Author: bideb
 */

#ifndef BACKEND_STATE_H_
#define BACKEND_STATE_H_

#include <vector>

#include "../entity/Entity.h"
#include <SFML/Graphics/RenderWindow.hpp>

namespace sf {
class Drawable;
} /* namespace sf */

class Entity;

class State {
public:
	State();
	virtual ~State();

	virtual void load() = 0;
	virtual void init() = 0;
	virtual void render() = 0;
	virtual void update() = 0;
	virtual void onExit() = 0;
	void draw(sf::Drawable& drawable);

	std::vector<Entity*> bullets;
};

#endif /* BACKEND_STATE_H_ */

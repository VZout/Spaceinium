/*
 * MenuState.h
 *
 *  Created on: May 31, 2015
 *      Author: bideb
 */

#ifndef STATES_MENUSTATE_H_
#define STATES_MENUSTATE_H_

#include <SFML/Audio/Music.hpp>
#include <vector>

#include "../backend/common/State.h"
#include "../backend/graphics/Particle.h"
#include "../backend/graphics/Sprite.h"
#include "../gui/OptionsMenuGroup.h"
#include "../gui/StartMenuGroup.h"

class StartMenuGroup;
class OptionsMenuGroup;

class MenuState : public State {
private:
	float particleTimer;
	float delay;

	sf::Music music;
	std::vector<Particle> particles;
	Sprite particleSprite;

public:
	MenuState();
	virtual ~MenuState();

	void load();
	void init();
	void render();
	void update();
	void onExit();

	StartMenuGroup mainGroup;
	OptionsMenuGroup optionsGroup;

	float randomFloatRange(float min, float max) {
		return (min + 1) + (((float) rand()) / (float) RAND_MAX) * (max - (min + 1));
	}

};


#endif /* STATES_MENUSTATE_H_ */


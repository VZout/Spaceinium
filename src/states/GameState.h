/*
 * GameState.h
 *
 *  Created on: Jul 20, 2015
 *      Author: bideb
 */

#ifndef STATES_GAMESTATE_H_
#define STATES_GAMESTATE_H_

#include "../backend/common/Map.h"
#include "../backend/common/State.h"
#include "../backend/entity/Player.h"

class GameState : public State {
public:
	GameState();
	virtual ~GameState();

	Map map;
	Player player;

	void load();
	void init();
	void render();
	void update();
	void onExit();
};

#endif /* STATES_GAMESTATE_H_ */

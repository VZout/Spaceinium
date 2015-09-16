/*
 * StartMenuGroup.h
 *
 *  Created on: Jun 9, 2015
 *      Author: bideb
 */

#ifndef GUI_STARTMENUGROUP_H_
#define GUI_STARTMENUGROUP_H_

#include <SFML/System/Vector2.hpp>

#include "../backend/gui/MenuList.h"
#include "../backend/common/ObjectGroup.h"
#include "../backend/gui/Text.h"
#include "../backend/gui/TextButton.h"

class MenuState;

class StartMenuGroup : public ObjectGroup {
private:
	Text playText;
	Text optionsText;
	Text quitText;

	TextButton playButton;
	TextButton optionsButton;
	TextButton quitButton;

public:
	MenuState* parent;

	MenuList buttonlist;

	StartMenuGroup();
	StartMenuGroup(sf::Vector2f pos, MenuState* parent);
	virtual ~StartMenuGroup();

	void init();
	void render();
	void update();

	void optionsAction();
};

#endif /* GUI_STARTMENUGROUP_H_ */

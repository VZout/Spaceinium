/*
 * OptionsMenuGroup.h
 *
 *  Created on: Jul 16, 2015
 *      Author: bideb
 */

#ifndef GUI_OPTIONSMENUGROUP_H_
#define GUI_OPTIONSMENUGROUP_H_

#include <SFML/System/Vector2.hpp>

#include "../backend/common/ObjectGroup.h"
#include "../backend/gui/MenuList.h"
#include "../backend/gui/Text.h"
#include "../backend/gui/TextButton.h"
#include "../backend/gui/Toggle.h"

class MenuState;

class OptionsMenuGroup : public ObjectGroup {
private:
	MenuState* parent;

	Text fullscreenText;
	Text backText;

	Toggle fullscreenToggle;
	TextButton backButton;

public:
	MenuList buttonlist;

	OptionsMenuGroup();
	OptionsMenuGroup(sf::Vector2f pos, MenuState* parent);
	virtual ~OptionsMenuGroup();

	void init();
	void render();
	void update();

	void fullscreenAction();
	void backAction();
};

#endif /* GUI_OPTIONSMENUGROUP_H_ */

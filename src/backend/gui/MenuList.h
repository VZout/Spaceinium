/*
 * MenuList.h
 *
 *  Created on: Jun 8, 2015
 *      Author: bideb
 */

#ifndef BACKEND_MENULIST_H_
#define BACKEND_MENULIST_H_

#include <vector>

#include "InteractableUIElement.h"

class MenuList {
private:
	unsigned int current;
public:
	std::vector<InteractableUIElement*> buttons;
	bool active;

	MenuList();
	virtual ~MenuList();

	void next();
	void prev();
	void render();
	void update();
	void press();
	int getCurrentID();
	void add(InteractableUIElement* button);
	void setActive(bool value);
};

#endif /* BACKEND_MENULIST_H_ */

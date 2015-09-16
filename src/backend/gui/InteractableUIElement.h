/*
 * InteractableUIElement.h
 *
 *  Created on: Jul 17, 2015
 *      Author: bideb
 */

#ifndef BACKEND_GUI_INTERACTABLEUIELEMENT_H_
#define BACKEND_GUI_INTERACTABLEUIELEMENT_H_

#include <functional>

class InteractableUIElement {
public:
	unsigned int id;
	bool selected;
	std::function<void()> action;

	InteractableUIElement(unsigned int id, bool selected, std::function<void()> action);
	virtual ~InteractableUIElement();

	virtual void render() = 0;
	virtual void update() = 0;
	virtual void press() = 0;
};

#endif /* BACKEND_GUI_INTERACTABLEUIELEMENT_H_ */

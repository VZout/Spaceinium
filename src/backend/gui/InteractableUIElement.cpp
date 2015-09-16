/*
 * InteractableUIElement.cpp
 *
 *  Created on: Jul 17, 2015
 *      Author: bideb
 */

#include "InteractableUIElement.h"

InteractableUIElement::InteractableUIElement(unsigned int id, bool selected, std::function<void()> action) {
	this->id = id;
	this->selected = selected;
	this->action = action;
}

InteractableUIElement::~InteractableUIElement() {
}


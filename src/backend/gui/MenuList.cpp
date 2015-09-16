/*
 * MenuList.cpp
 *
 *  Created on: Jun 8, 2015
 *      Author: bideb
 */

#include "MenuList.h"

#include <iostream>

MenuList::MenuList() {
	current = 0;
	active = true;
}

MenuList::~MenuList() {
}

void MenuList::add(InteractableUIElement* button) {
	buttons.push_back(button);
}

void MenuList::next() {
	if(active) {
		buttons[current]->selected = false;
		current++;
		if(current > (buttons.size() - 1)) {
			current = 0;
		}

		for(unsigned int i = 0; i < buttons.size(); i++) {
			if(buttons[i]->id == (current)) {
				buttons[i]->selected = true;
			}
		}
	}
}

void MenuList::prev() {
	if(active) {
		buttons[current]->selected = false;
		if(current == 0) {
			current = buttons.size() - 1;
		} else {
			current--;
		}

		for(unsigned int i = 0; i < buttons.size(); i++) {
			if(buttons[i]->id == (current)) {
				buttons[i]->selected = true;
			}
		}
	}
}

void MenuList::update() {
	for(unsigned int i = 0; i < buttons.size(); i++) {
		buttons[i]->update();
	}
}

void MenuList::render() {
	for(unsigned int i = 0; i < buttons.size(); i++) {
		buttons[i]->render();
	}
}

void MenuList::press() {
	if(active) {
		buttons[current]->press();
	}
}

void MenuList::setActive(bool value) {
	active = value;
	if(value) {
		buttons[current]->selected = true;
	} else {
		for(unsigned int i = 0; i < buttons.size(); i++) {
			buttons[i]->selected = false;
		}
	}
}


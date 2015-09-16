/*
 * Toggle.h
 *
 *  Created on: Jul 17, 2015
 *      Author: bideb
 */

#ifndef BACKEND_GUI_TOGGLE_H_
#define BACKEND_GUI_TOGGLE_H_

#include <SFML/Graphics/Color.hpp>
#include <functional>

#include "../graphics/AnimatedSprite.h"
#include "../graphics/Sprite.h"
#include "InteractableUIElement.h"
#include "Text.h"

class Toggle : public InteractableUIElement {
private:
	AnimatedSprite sprite;
	Sprite spriteOn;
	Sprite spriteOff;

public:
	bool value;

	Text text;
	sf::Color normalColor;
	sf::Color selectedColor;

	Toggle();
	Toggle(unsigned int id, bool selected, Text text, sf::Color selectedColor, std::function<void()> action);
	virtual ~Toggle();

	void render();
	void update();
	void press();
};

#endif /* BACKEND_GUI_TOGGLE_H_ */

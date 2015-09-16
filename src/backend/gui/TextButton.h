/*
 * TextButton.h
 *
 *  Created on: Jun 3, 2015
 *      Author: bideb
 */

#ifndef UI_TEXTBUTTON_H_
#define UI_TEXTBUTTON_H_

#include <SFML/Graphics/Color.hpp>
#include <functional>

#include "../graphics/AnimatedSprite.h"
#include "InteractableUIElement.h"
#include "Text.h"

class TextButton : public InteractableUIElement {
private:
	AnimatedSprite sprite;
public:
	Text text;
	sf::Color normalColor;
	sf::Color selectedColor;

	TextButton();
	TextButton(int id, bool selected, Text text, sf::Color selectedColor, std::function<void()> action);
	virtual ~TextButton();

	void render();
	void update();
	void press();
};

#endif /* UI_TEXTBUTTON_H_ */

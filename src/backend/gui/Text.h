/*
 * Text.h
 *
 *  Created on: Jun 3, 2015
 *      Author: bideb
 */

#ifndef UI_TEXT_H_
#define UI_TEXT_H_

#include <SFML/Graphics/Text.hpp>

class Text {
private:
public:
	Text();
	Text(const char* value, int size, sf::Font& font);
	Text(const char* value, int x, int y, int size, sf::Font& font);
	virtual ~Text();

	enum Origin {
		LEFT,
		RIGHT,
		CENTER
	};

	sf::Text text;

	float getWidth();
	float getHeight();
	void setOrigin(Origin origin);
	void setColor(sf::Color color);
	sf::Color getColor();

	void render();

};

#endif /* UI_TEXT_H_ */

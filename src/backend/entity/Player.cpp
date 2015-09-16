/*
 * Player.cpp
 *
 *  Created on: Jul 28, 2015
 *      Author: bideb
 */

#include "Player.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

#include "../common/Input.h"
#include "../common/Resources.h"
#include "../../projectiles/Projectile.h"

#include <cmath>

//TODO vector2 direction, float,acceleration and a float velocity should add better movement.

Player::Player() {
	friction = 0.8;
	accelSpeed = 3;
	maxSpeed = 6;
	weaponRotation = 0;

	position = sf::Vector2f(0,0);
	acceleration = sf::Vector2f(0,0);
	velocity = sf::Vector2f(0,0);

}

Player::Player(sf::Vector2f position) {
	friction = 0.8;
	accelSpeed = 1;
	maxSpeed = 6;
	weaponRotation = 0;

	this->position = position;
}

Player::~Player() {
	// TODO Auto-generated destructor stub
}

void Player::init(State* state) {
	acceleration = sf::Vector2f(0,0);
	velocity = sf::Vector2f(0,0);

	spritesheet = Resources::getCharacterImage(0);

	walk0.loadFromImage(spritesheet, sf::IntRect(0, 0, 16, 16));

	sprite = AnimatedSprite(position.x, position.y, 4, 1, 2, walk0);

	sprite.addFrame(0, walk0);
	walk1.loadFromImage(spritesheet, sf::IntRect(16, 0, 32, 16));
	sprite.addFrame(0, walk1);

	sprite.getSprite().sprite.setOrigin
		(sprite.getSprite().sprite.getTexture()->getSize().x / 2,
		 sprite.getSprite().sprite.getTexture()->getSize().y / 2);

	weaponSprite = Sprite(Resources::getWeaponTexture(0), 100, 100, 3);
	weaponSprite.setOriginToCenter();
}

void Player::render() {
	sprite.render();
	weaponSprite.render();
}

void Player::update() {
	sprite.update();
	weaponSprite.update();

	handleInput();
	handlePhysics();
	
	sprite.setPosition(position.x, position.y);
	weaponSprite.setPosition(position.x, position.y);

	rotateWeaponTowardsMouse();

	if(Input::getMousePos().x > position.x) {
		sprite.setScale(4, 4);
		weaponSprite.setScale(3, 3);
	}

	if(Input::getMousePos().x < position.x) {
		sprite.setScale(-4, 4);
		weaponSprite.setScale(3, -3);
	}
}

void Player::handleInput() {
	float speed = accelSpeed * acceleration.x != 0 && acceleration.y != 0 ? 0.7071f : 1;

	if (Input::getHeld(sf::Keyboard::D)) {
		acceleration.x = speed;
	} else if (Input::getHeld(sf::Keyboard::A)) {
		acceleration.x = -speed;
	} else {
		acceleration.x = 0;
	}

	if (Input::getHeld(sf::Keyboard::W)) {
		acceleration.y = -speed;
	} else if (Input::getHeld(sf::Keyboard::S)) {
		acceleration.y = speed;
	} else {
		acceleration.y = 0;
	}

	if(Input::getDown(sf::Keyboard::Space)) {
		fire();
	}
}

void Player::rotateWeaponTowardsMouse() {
	int mx = Input::getMousePos().x;
	int my = Input::getMousePos().y;
	float cx = position.x;	
	float cy = position.y;
	float dx = mx - cx;
	float dy = my - cy;
	float newRotation = std::atan2(dy, dx) *  (180 / (std::atan(1)*4));
	weaponRotation = newRotation;

	weaponSprite.setRotation(weaponRotation);
}

void Player::fire() {
	Projectile* p = new Projectile(10.f, position, weaponRotation);
	p->init(*Spaceinium::currentState);
	Spaceinium::currentState->bullets.push_back(p);
}

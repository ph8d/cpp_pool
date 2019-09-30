#include "Player.class.hpp"

void Player::moveUp(void) {
	this->position.y--;
}

void Player::moveDown(void) {
	this->position.y++;
}

void Player::moveLeft(void) {
	this->position.x--;
}

void Player::moveRight(void) {
	this->position.x++;
}

Player::Player(void):
GameEntity("^", 100, 1, Position()) { }

Player::Player(Position pos):
GameEntity("^", 100, 1, pos) { }

Player::~Player(void) { }
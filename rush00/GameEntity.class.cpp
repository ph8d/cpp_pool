#include "GameEntity.class.hpp"

bool GameEntity::isCollidingWith(const GameEntity & entity) const {
	return this->position == entity.position;
}

bool GameEntity::isDead(void) const {
	return this->_hp == 0;
}

int GameEntity::getHP(void) const {
	return this->_hp;
}

int GameEntity::getSpeed(void) const {
	return this->_speed;
}

const char* GameEntity::getDispChar(void) const {
	return (this->_disp_char.data());
}

void GameEntity::setDisplayChar(std::string str) {
	this->_disp_char = str;
}

void GameEntity::setHP(int amount) {
	this->_hp = amount;
}

void GameEntity::setSpeed(int speed) {
	this->_speed = speed;
}

void GameEntity::setPosition(int x, int y) {
	this->position.x = x;
	this->position.y = y;
}

void GameEntity::setPosition(Position pos) {
	this->position = pos;
}

void GameEntity::takeDamage(int amount) {
	this->_hp -= amount;
	if (this->_hp < 0) {
		this->_hp = 0;
	}
}

void GameEntity::clearEntity(void) {
	this->position = Position(-1, -1);
}

GameEntity & GameEntity::operator=(GameEntity const & rhs) {
	this->_hp = rhs._hp;
	this->_speed = rhs._speed;
	this->position = rhs.position;

	return *this;
}

GameEntity::GameEntity(const GameEntity& toCopy):
_hp(toCopy._hp), _speed(toCopy._speed) {
	this->position = toCopy.position;
}

GameEntity::GameEntity(std::string disp_char, int hp, int movingSpeed, Position pos):
_disp_char(disp_char), _hp(hp), _speed(movingSpeed), position(pos) { }

GameEntity::GameEntity(void): _disp_char("[E]"), _hp(0), _speed(1), position(Position()) { }
GameEntity::~GameEntity(void) { }
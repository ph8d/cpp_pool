#include "Enemy.class.hpp"
#include <iostream>

void Enemy::takeDamage(int amount) {
	this->_hp -= amount;
}

int Enemy::getHP(void) const {
	return this->_hp;
}

std::string Enemy::getType(void) const {
	return this->_type;
}

Enemy & Enemy::operator=(Enemy const & rhs) {
	this->_hp = rhs.getHP();
	this->_type = rhs.getType();

	return *this;
}

Enemy::Enemy(const Enemy & toCopy): _hp(toCopy.getHP()), _type(toCopy.getType()) { }
Enemy::Enemy(int hp, std::string const & type): _hp(hp), _type(type) { }
Enemy::~Enemy(void) { }
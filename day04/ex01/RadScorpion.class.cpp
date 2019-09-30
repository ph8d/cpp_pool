#include "RadScorpion.class.hpp"
#include <iostream>

void RadScorpion::takeDamage(int amount) {
	this->_hp -= amount;
}

RadScorpion & RadScorpion::operator=(const RadScorpion & toCopy) {
	this->_hp = toCopy.getHP();
	this->_type = toCopy.getType();
	
	return *this;
}

RadScorpion::RadScorpion(const RadScorpion & toCopy): Enemy(toCopy.getHP(), toCopy.getType()) { }

RadScorpion::RadScorpion(void): Enemy(80, "RadScorpion") {
	std::cout << "* click click click *" << std::endl;
}
RadScorpion::~RadScorpion(void) {
	std::cout << "* SPROTCH *" << std::endl;
}
#include "SuperMutant.class.hpp"
#include <iostream>

void SuperMutant::takeDamage(int amount) {
	this->_hp -= (amount - 3);
}

SuperMutant & SuperMutant::operator=(const SuperMutant & toCopy) {
	this->_hp = toCopy.getHP();
	this->_type = toCopy.getType();
	
	return *this;
}

SuperMutant::SuperMutant(const SuperMutant & toCopy): Enemy(toCopy.getHP(), toCopy.getType()) { }

SuperMutant::SuperMutant(void): Enemy(170, "Super Mutant") {
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}
SuperMutant::~SuperMutant(void) {
	std::cout << "Aaargh ..." << std::endl;
}
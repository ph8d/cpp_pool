#include "PowerFist.class.hpp"

void PowerFist::attack(void) const{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}

PowerFist & PowerFist::operator=(PowerFist const & rhs) {
	this->_name = rhs.getName();
	this->_apCost = rhs.getAPCost();
	this->_damage = rhs.getDamage();

	return *this;
}

PowerFist::PowerFist(const PowerFist & toCopy):
AWeapon(toCopy.getName(), toCopy.getAPCost(), toCopy.getDamage()) {
	return;
}

PowerFist::PowerFist(void): AWeapon("Power Fist", 8, 50) {
	return;
}

PowerFist::~PowerFist(void) {
	return;
}
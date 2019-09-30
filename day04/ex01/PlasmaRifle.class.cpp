#include "PlasmaRifle.class.hpp"

void PlasmaRifle::attack(void) const{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}

PlasmaRifle & PlasmaRifle::operator=(PlasmaRifle const & rhs) {
	this->_name = rhs.getName();
	this->_apCost = rhs.getAPCost();
	this->_damage = rhs.getDamage();

	return *this;
}

PlasmaRifle::PlasmaRifle(const PlasmaRifle & toCopy):
AWeapon(toCopy.getName(), toCopy.getAPCost(), toCopy.getDamage()) {
	return;
}

PlasmaRifle::PlasmaRifle(void): AWeapon("Plasma Rifle", 5, 21) {
	return;
}

PlasmaRifle::~PlasmaRifle(void) {
	return;
}
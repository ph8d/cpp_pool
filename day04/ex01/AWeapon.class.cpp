#include "AWeapon.class.hpp"

std::string AWeapon::getName(void) const {
	return this->_name;
}

int AWeapon::getAPCost(void) const {
	return this->_apCost;
}

int AWeapon::getDamage(void) const {
	return this->_damage;
}

// AWeapon & AWeapon::operator=(AWeapon const & rhs) {
// 	this->_name = rhs.getName();
// 	this->_apCost = rhs.getAPCost();
// 	this->_damage = rhs.getDamage();

// 	return *this;
// }

AWeapon::AWeapon(std::string const & name, int apCost, int damage):
_name(name), _damage(damage), _apCost(apCost) {
	return;
}

// AWeapon::AWeapon(const AWeapon & toCopy) {
// 	return;
// }

AWeapon::~AWeapon(void) {
	return;
}
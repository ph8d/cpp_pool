#include "Character.class.hpp"

std::string Character::getName(void) const {
	return this->_name;
}

std::string Character::getWeaponType(void) const {
	if (this->_weapon != NULL) {
		return this->_weapon->getName();
	}
	return "";
}

int Character::getAP(void) const {
	return this->_ap;
}

void Character::recoverAP(void) {
	this->_ap += 10;
	if (this->_ap > 40) {
		this->_ap = 40;
	}
}

void Character::equip(AWeapon* weapon) {
	this->_weapon = weapon;
}

void Character::attack(Enemy* enemy) {
	if (this->_weapon != NULL && this->_ap - this->_weapon->getAPCost() >= 0) {
		std::cout << this->getName() + " attacks " + enemy->getType() + " with a " + this->_weapon->getName() << std::endl;
		this->_weapon->attack();

		this->_ap -= this->_weapon->getAPCost();

		enemy->takeDamage(this->_weapon->getDamage());
		if (enemy->getHP() <= 0) {
			enemy->~Enemy();
		}
	}
}

Character::Character(std::string const & name): _name(name), _ap(40), _weapon(NULL) { }
Character::Character(const Character & toCopy): _name(toCopy.getName()), _ap(toCopy.getAP()) { }

Character::~Character(void) { }

std::ostream & operator<<(std::ostream & o, Character const & rhs) {
	if (!rhs.getWeaponType().empty()) {
		o << rhs.getName() + " has " << rhs.getAP() << " AP and wields a " + rhs.getWeaponType() << std::endl;		
	} else {
		o << rhs.getName() + " has " << rhs.getAP() << " AP and is unarmed" << std::endl;
	}
	return o;
}
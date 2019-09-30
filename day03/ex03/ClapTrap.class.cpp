#include "ClapTrap.class.hpp"

std::string ClapTrap::getName(void) const {
	return this->_name;
}

int ClapTrap::_countDamageReduction(unsigned int amount) {
	if (this->_armorDamageReduction > 0) {
		return (amount - (((this->_armorDamageReduction * amount) / 100) * 2));
	}
	return amount;
}

void ClapTrap::rangeAttack(std::string const & target) {
	std::cout << "* " + this->_name + " attacks " + target + " at range, causing " << this->_rangeDamage << " damage! *" << std::endl;
	this->say("Get off my lawn!");
}

void ClapTrap::meleeAttack(std::string const & target) {
	std::cout << " * " + this->_name + " hits " + target + " in the face with melee, causing " << this->_meleeDamage << " damage! * " << std::endl;
	this->say("Bop!");
}

void ClapTrap::takeDamage(unsigned int amount) {
	int reducedAmount = this->_countDamageReduction(amount);

	std::cout << "* " + this->_name + " takes " << reducedAmount << " damage! *" << std::endl;

	this->_hitPoints -= reducedAmount;

	if (this->_hitPoints < 0) {
		this->_hitPoints = 0;
		this->say("Are you god? Am I dead?");
	} else {
		this->say("My robotic flesh! AAHH!!!");
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "* " + this->_name + " gets repaired for " << amount << " hit points *" << std::endl;

	this->_hitPoints += amount;

	if (this->_hitPoints > this->_maxHitPoints) {
		this->_hitPoints = this->_maxHitPoints;
	}
	
	this->say("Sweet life juice!");
}

void ClapTrap::say(std::string text) {
	std::cout << "<" + this->_name + " [" << this->_hitPoints << "HP]>: " + text << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs) {
	this->_name = rhs._name;
	this->_level = rhs._level;
	this->_hitPoints = rhs._hitPoints;
	this->_maxHitPoints = rhs._maxHitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_maxEnergyPoints = rhs._maxEnergyPoints;
	this->_meleeDamage = rhs._meleeDamage;
	this->_rangeDamage = rhs._rangeDamage;
	this->_armorDamageReduction = rhs._armorDamageReduction;

	return *this;
}

ClapTrap::ClapTrap(const ClapTrap& toCopy) {
	std::cout << "* A copy of ClapTrap <" + toCopy.getName() + "> appeared! *" << std::endl;

	this->_name = toCopy._name;
	this->_level = toCopy._level;
	this->_hitPoints = toCopy._hitPoints;
	this->_maxHitPoints = toCopy._maxHitPoints;
	this->_energyPoints = toCopy._energyPoints;
	this->_maxEnergyPoints = toCopy._maxEnergyPoints;
	this->_meleeDamage = toCopy._meleeDamage;
	this->_rangeDamage = toCopy._rangeDamage;
	this->_armorDamageReduction = toCopy._armorDamageReduction;

	this->say("I'm a copy of robot...");
	return;
}

ClapTrap::ClapTrap() {
	std::cout << "* A ClapTrap appeared! *" << std::endl;
	return;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "* A ClapTrap was destroyed *" << std::endl;
	return;
}


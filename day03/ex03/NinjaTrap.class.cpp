#include "NinjaTrap.class.hpp"

void NinjaTrap::ninjaShoebox(FragTrap& fragTrap) {
	this->meleeAttack(fragTrap.getName());
	fragTrap.takeDamage(this->_meleeDamage);
}

void NinjaTrap::ninjaShoebox(ScavTrap& scavTrap) {
	this->rangeAttack(scavTrap.getName());
	scavTrap.takeDamage(this->_rangeDamage);
}

void NinjaTrap::ninjaShoebox(NinjaTrap& ninjaTrap) {
	this->say("Oh! Hi brother, let's fix you up a bit!");
	ninjaTrap.beRepaired(35);
}

NinjaTrap & NinjaTrap::operator=(NinjaTrap const & rhs) {
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

NinjaTrap::NinjaTrap(std::string name) {
	std::cout << "* A NinjaTrap <" + name + "> appeared! *" << std::endl;

	this->_name = name;
	this->_level = 1;
	this->_hitPoints = 60;
	this->_maxHitPoints = 60;
	this->_energyPoints = 120;
	this->_maxEnergyPoints = 120;
	this->_meleeDamage = 60;
	this->_rangeDamage = 5;
	this->_armorDamageReduction = 0;

	this->say("I'm a robot ninja...");
	return;
}

NinjaTrap::NinjaTrap(const NinjaTrap& toCopy) {
	std::cout << "* A copy of NinjaTrap <" + toCopy.getName() + "> appeared! *" << std::endl;

	this->_name = toCopy._name;
	this->_level = toCopy._level;
	this->_hitPoints = toCopy._hitPoints;
	this->_maxHitPoints = toCopy._maxHitPoints;
	this->_energyPoints = toCopy._energyPoints;
	this->_maxEnergyPoints = toCopy._maxEnergyPoints;
	this->_meleeDamage = toCopy._meleeDamage;
	this->_rangeDamage = toCopy._rangeDamage;
	this->_armorDamageReduction = toCopy._armorDamageReduction;

	this->say("I'm a copy of robot ninja...");
	return;
}

NinjaTrap::~NinjaTrap(void) {
	std::cout << "* A NinjaTrap <" + this->_name + "> was destroyed *" << std::endl;
	this->say("Crap happens.");
	return;
}
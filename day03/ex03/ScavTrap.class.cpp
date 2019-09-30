#include "ScavTrap.class.hpp"

void ScavTrap::challengeNewcomer(void) {
	std::string challenges[] = {
		" kill Dark Siders and bringing back the proof.",
		" give me all your loot. C'mon you dont need it anyway, right?",
		" dance. Lets dance right here and right now!",
		" scratch my back. It keeps itching and i can't reach that spot with my tiny hands."
	};

	int index = rand() % 4;
	this->say("Hey, newcomer! Yes you, i challange you to" + challenges[index]);
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs) {
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

ScavTrap::ScavTrap(const ScavTrap& toCopy) {
	std::cout << "* A copy of ScavTrap <" + toCopy._name + "> appeared! *" << std::endl;

	this->_name = toCopy._name;
	this->_level = toCopy._level;
	this->_hitPoints = toCopy._hitPoints;
	this->_maxHitPoints = toCopy._maxHitPoints;
	this->_energyPoints = toCopy._energyPoints;
	this->_maxEnergyPoints = toCopy._maxEnergyPoints;
	this->_meleeDamage = toCopy._meleeDamage;
	this->_rangeDamage = toCopy._rangeDamage;
	this->_armorDamageReduction = toCopy._armorDamageReduction;

	this->say("I'm a copy of a robot...");
	return;
}

ScavTrap::ScavTrap(std::string name) {
	std::cout << "* A ScavTrap <" + name + "> appeared! *" << std::endl;

	this->_name = name;
	this->_level = 1;
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 50;
	this->_maxEnergyPoints = 50;
	this->_meleeDamage = 20;
	this->_rangeDamage = 15;
	this->_armorDamageReduction = 3;

	this->say("Recompiling my combat code!");
	return;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "* A ScavTrap " + this->_name + " was destroyed *" << std::endl;
	this->say("NOOO!");
	return;
}
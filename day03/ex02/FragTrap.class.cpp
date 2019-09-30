#include "FragTrap.class.hpp"

void FragTrap::vaulthunter_dot_exe(std::string const & target) {
	if (this->_energyPoints - 25 < 0) {
		std::cout << "* VaultHunter.EXE not enough energy *" << std::endl;
		return;
	}

	this->_energyPoints -= 25;

	std::string attacks[] = {
		" throws out a turret that sprays bullets at ",
		" shoots laser beams from disco ball on his head ",
		" turns into a rubber duck and reflects all the bullets at ",
		" starts throwing a lot of grenades at ",
		" shoots one very powerfull bullet at "
	};
	
	std::string quotes[] = {
		"Don't ask me where this bullets is coming from!",
		"Everybody, dance time! Da-da-da-dun-daaa-da-da-da-dun-daaa!",
		"Boiyoiyoiyoiyoing!",
		"I brought you a present: EXPLOSIONS!",
		"Like those guys who made only one song ever."
	};

	int index = rand() % 5;
	int damage = 100 + (rand() % 78);

	std::cout << "* VaultHunter.EXE activated *" << std::endl;
	this->say(quotes[index]);
	std::cout << "* FR4G-TP " + this->_name + attacks[index] + target + " causing " << damage << " damage *" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs) {
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

FragTrap::FragTrap(const FragTrap& toCopy) {
	std::cout << "* A copy of FragTrap <" + toCopy._name + "> appeared! *" << std::endl;

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

FragTrap::FragTrap(std::string name) {
	std::cout << "* A FragTrap <" + name + "> appeared! *" << std::endl;

	this->_name = name;
	this->_level = 1;
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 100;
	this->_maxEnergyPoints = 100;
	this->_meleeDamage = 30;
	this->_rangeDamage = 20;
	this->_armorDamageReduction = 5;

	this->say("This time it'll be awesome, I promise!");
	return;
}

FragTrap::~FragTrap(void) {
	std::cout << "* A FragTrap <" + this->_name + "> was destroyed *" << std::endl;
	this->say("Argh arghargh death gurgle gurglegurgle urgh... death.");
	return;
}
#ifndef SCAVTRAP_CLASS_HPP
# define SCAVTRAP_CLASS_HPP

#include <iostream>

class ScavTrap {

private:
	std::string _name;

	int _level;
	int _hitPoints; 
	int _maxHitPoints;
	int _energyPoints;
	int _maxEnergyPoints;
	int _meleeDamage;
	int _rangeDamage;
	int _armorDamageReduction;

public:
	void rangeAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void challengeNewcomer(void);
	void say(std::string text);

	ScavTrap & operator=(ScavTrap const & rhs);

	ScavTrap(const ScavTrap & toCopy);
	ScavTrap(std::string name);
	~ScavTrap(void);


};

#endif
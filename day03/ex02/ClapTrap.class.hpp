#ifndef CLAPTRAP_CLASS_HPP
# define CLAPTRAP_CLASS_HPP

#include <iostream>

class ClapTrap {

protected:
	std::string _name;

	int _level;
	int _hitPoints; 
	int _maxHitPoints;
	int _energyPoints;
	int _maxEnergyPoints;
	int _meleeDamage;
	int _rangeDamage;
	int _armorDamageReduction;

	int _countDamageReduction(unsigned int amount);
	

public:
	std::string getName(void) const;
	void rangeAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void say(std::string text);

	ClapTrap & operator=(ClapTrap const & rhs);

	ClapTrap(const ClapTrap & toCopy);
	ClapTrap(void);
	~ClapTrap(void);

};

#endif
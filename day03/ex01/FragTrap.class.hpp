#ifndef FRAGTRAP_CLASS_HPP
# define FRAGTRAP_CLASS_HPP

#include <iostream>

class FragTrap {

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
	void vaulthunter_dot_exe(std::string const & target);
	void say(std::string text);

	FragTrap & operator=(FragTrap const & rhs);

	FragTrap(std::string name);
	FragTrap(const FragTrap& toCopy);
	~FragTrap(void);

};

#endif
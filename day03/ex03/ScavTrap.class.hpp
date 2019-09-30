#ifndef SCAVTRAP_CLASS_HPP
# define SCAVTRAP_CLASS_HPP

# include <iostream>
# include "ClapTrap.class.hpp"

class ScavTrap: public ClapTrap {

public:
	void challengeNewcomer(void);

	ScavTrap & operator=(ScavTrap const & rhs);

	ScavTrap(const ScavTrap & toCopy);
	ScavTrap(std::string name);
	~ScavTrap(void);

};

#endif
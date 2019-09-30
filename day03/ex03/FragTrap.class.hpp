#ifndef FRAGTRAP_CLASS_HPP
# define FRAGTRAP_CLASS_HPP

#include <iostream>
#include "ClapTrap.class.hpp"

class FragTrap: public ClapTrap {


public:
	void vaulthunter_dot_exe(std::string const & target);
	
	FragTrap & operator=(FragTrap const & rhs);

	FragTrap(std::string name);
	FragTrap(const FragTrap& toCopy);
	~FragTrap(void);

};

#endif
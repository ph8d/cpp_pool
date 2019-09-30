#ifndef NINJATRAP_CLASS_HPP
# define NINJATRAP_CLASS_HPP

# include "ClapTrap.class.hpp"
# include "FragTrap.class.hpp"
# include "ScavTrap.class.hpp"

class NinjaTrap: public ClapTrap {

public:
	void ninjaShoebox(FragTrap& fragTrap);
	void ninjaShoebox(ScavTrap& scavTrap);
	void ninjaShoebox(NinjaTrap& ninjaTrap);

	NinjaTrap & operator=(NinjaTrap const & rhs);

	NinjaTrap(std::string name);
	NinjaTrap(const NinjaTrap& toCopy);
	~NinjaTrap(void);

};

#endif
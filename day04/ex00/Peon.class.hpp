#ifndef PEON_CLASS_HPP
# define PEON_CLASS_HPP

# include <iostream>
# include "Victim.class.hpp"

class Peon: public Victim {

private:
	std::string _name;

public:
	void getPolymorphed(void) const;
	Peon & operator=(Peon const & rhs);
	Peon(std::string name);
	Peon(const Peon& toCopy);
	~Peon(void);

};

#endif
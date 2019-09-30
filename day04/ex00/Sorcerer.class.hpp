#ifndef SORCERER_CLASS_HPP
# define SORCERER_CLASS_HPP

# include <iostream>
# include "Victim.class.hpp"

class Sorcerer {

private:
	std::string _name;
	std::string _title;

public:
	std::string getName(void) const;
	std::string getTitle(void) const;
	void polymorph(Victim const & victim) const;

	Sorcerer & operator=(Sorcerer const & rhs);

	Sorcerer(std::string name, std::string title);
	Sorcerer(const Sorcerer& toCopy);
	~Sorcerer(void);


};

std::ostream & operator<<(std::ostream & o, Sorcerer const & rhs);

#endif
#ifndef VICTIM_CLASS_HPP
# define VICTIM_CLASS_HPP

# include <iostream>

class Victim {

protected:
	Victim(void);
	std::string _name;

public:
	virtual void getPolymorphed(void) const;
	std::string getName(void) const;
	Victim & operator=(Victim const & rhs);
	Victim(std::string name);
	Victim(const Victim& toCopy);
	~Victim(void);

};

std::ostream & operator<<(std::ostream & o, Victim const & rhs);

#endif
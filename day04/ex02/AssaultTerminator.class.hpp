#ifndef ASSAULTTERMINATOR_CLASS_HPP
# define ASSAULTTERMINATOR_CLASS_HPP

# include "ISpaceMarine.class.hpp"
# include <iostream>

class AssaultTerminator: public ISpaceMarine {

protected:
	std::string _battleCry;

public:
	ISpaceMarine* clone(void) const;
	virtual void battleCry(void) const;
	virtual void rangedAttack(void) const;
	virtual void meleeAttack(void) const;
	AssaultTerminator & operator=(AssaultTerminator const & rhs);
	AssaultTerminator(const AssaultTerminator & toCopy);
	AssaultTerminator(void);
	~AssaultTerminator(void);

};

#endif
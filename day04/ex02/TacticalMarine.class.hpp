#ifndef TACTICALMARINE_CLASS_HPP
# define TACTICALMARINE_CLASS_HPP

#include "ISpaceMarine.class.hpp"
#include <iostream>

class TacticalMarine: public ISpaceMarine  {

protected:
	std::string _battleCry;

public:
	ISpaceMarine* clone(void) const;
	virtual void battleCry(void) const;
	virtual void rangedAttack(void) const;
	virtual void meleeAttack(void) const;
	TacticalMarine & operator=(TacticalMarine const & rhs);
	TacticalMarine(const TacticalMarine & toCopy);
	TacticalMarine(void);
	~TacticalMarine(void);

};

#endif
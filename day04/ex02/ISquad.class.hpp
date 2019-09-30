#ifndef ISQUAD_CLASS_HPP
# define ISQUAD_CLASS_HPP

#include "ISpaceMarine.class.hpp"

class ISquad {

public:
	virtual ~ISquad() {}
	virtual int getCount() const = 0;
	virtual ISpaceMarine* getUnit(int) const = 0;
	virtual int push(ISpaceMarine*) = 0;

};

#endif
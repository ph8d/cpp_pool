#ifndef SQUAD_CLASS_HPP
# define SQUAD_CLASS_HPP

#include "ISquad.class.hpp"
#include "ISpaceMarine.class.hpp"
#include <iostream>

class Squad: public ISquad {

protected:
	static int const _maxSize = 16;
	int _squadSize;
	ISpaceMarine* _marines[16];

public:
	int getCount() const; 
	ISpaceMarine* getUnit(int index) const;
	int push(ISpaceMarine* marine);
	Squad & operator=(Squad const & rhs);
	Squad(const Squad & toCopy);
	Squad(void);
	~Squad(void);

};

#endif
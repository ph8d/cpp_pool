#ifndef POSITION_CLASS_HPP
# define POSITION_CLASS_HPP

#include <iostream>

class Position {

public:
	int x;
	int y;

	Position & operator=(Position const & rhs);
	
	bool operator==(Position const & rhs) const;

	Position(void);
	Position(int x, int y);
	Position(const Position & toCopy);
	~Position(void);

};

std::ostream & operator<<(std::ostream & o, Position const & rhs);

#endif
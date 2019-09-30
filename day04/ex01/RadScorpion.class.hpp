#ifndef RADSCORPION_CLASS_HPP
# define RADSCORPION_CLASS_HPP

#include "Enemy.class.hpp"

class RadScorpion: public Enemy {

public:
	void takeDamage(int amount);
	RadScorpion & operator=(RadScorpion const & rhs);
	RadScorpion(const RadScorpion & toCopy);
	RadScorpion(void);
	~RadScorpion(void);

};

#endif
#ifndef SUPERMUTANT_CLASS_HPP
# define SUPERMUTANT_CLASS_HPP

# include "Enemy.class.hpp"

class SuperMutant: public Enemy {

public:
	void takeDamage(int amount);
	SuperMutant & operator=(SuperMutant const & rhs);
	SuperMutant(const SuperMutant & toCopy);
	SuperMutant(void);
	~SuperMutant(void);

};

#endif
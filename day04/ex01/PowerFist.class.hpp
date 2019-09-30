#ifndef POWERFIST_CLASS_HPP
# define POWERFIST_CLASS_HPP

# include "AWeapon.class.hpp"

class PowerFist: public AWeapon {

public:
	void attack(void) const;
	PowerFist & operator=(PowerFist const & rhs);
	PowerFist(void);
	PowerFist(const PowerFist & toCopy);
	~PowerFist(void);

};

#endif
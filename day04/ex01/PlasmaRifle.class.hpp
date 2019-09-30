#ifndef PLASMARIFLE_CLASS_HPP
# define PLASMARIFLE_CLASS_HPP

# include "AWeapon.class.hpp"

class PlasmaRifle: public AWeapon {

public:
	void attack(void) const;
	PlasmaRifle & operator=(PlasmaRifle const & rhs);
	PlasmaRifle(void);
	PlasmaRifle(const PlasmaRifle & toCopy);
	~PlasmaRifle(void);

};

#endif
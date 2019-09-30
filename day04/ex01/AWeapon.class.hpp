#ifndef AWEAPON_CLASS_HPP
# define AWEAPON_CLASS_HPP

# include <iostream>

class AWeapon {

protected:
	std::string _name;
	int _damage;
	int _apCost;

public:
	virtual void attack(void) const = 0;
	std::string getName(void) const;
	int getAPCost(void) const;
	int getDamage(void) const;
	// AWeapon & operator=(AWeapon const & rhs);
	AWeapon(std::string const & name, int apCost, int damage);
	// AWeapon(const AWeapon & toCopy);
	virtual ~AWeapon(void);

};

#endif
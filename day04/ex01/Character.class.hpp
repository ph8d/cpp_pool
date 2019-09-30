#ifndef CHARACTER_CLASS_HPP
# define CHARACTER_CLASS_HPP

#include <iostream>
#include "AWeapon.class.hpp"
#include "Enemy.class.hpp"

class Character {

protected:
	std::string _name;
	int _ap;
	AWeapon* _weapon;

public:
	std::string getName(void) const;
	std::string getWeaponType(void) const;
	int getAP(void) const;
	void recoverAP(void);
	void equip(AWeapon* weapon);
	void attack(Enemy* enemy);
	Character & operator=(Character const & rhs);
	Character(std::string const & name);
	Character(const Character & toCopy);
	~Character(void);

};

std::ostream & operator<<(std::ostream & o, Character const & rhs);

#endif
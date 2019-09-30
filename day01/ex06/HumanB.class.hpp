#ifndef HUMANB_CLASS_HPP
# define HUMANB_CLASS_HPP

#include "Weapon.class.hpp"

class HumanB {

	private:
		std::string _name;
		Weapon* _weapon;

	public:
		void attack(void);
		void setWeapon(Weapon& weapon);
		HumanB(std::string name);
		~HumanB(void);
};

#endif
#ifndef HUMANA_CLASS_HPP
# define HUMANA_CLASS_HPP

#include "Weapon.class.hpp"

class HumanA {

	private:
		std::string _name;
		Weapon* _weapon;

	public:
		void attack(void);
		HumanA(std::string name, Weapon& weapon);
		~HumanA(void);

};

#endif
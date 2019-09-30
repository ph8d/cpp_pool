#ifndef WEAPON_CLASS_HPP
# define WEAPON_CLASS_HPP

#include <iostream>

class Weapon {

	private:
		std::string _type;

	public:
		void setType(std::string type);
		std::string& getType(void);
		Weapon(std::string type);
		~Weapon(void);

};

#endif
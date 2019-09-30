#ifndef ZOMBIEHORDE_CLASS_HPP
# define ZOMBIEHORDE_CLASS_HPP

#include "Zombie.class.hpp"

class ZombieHorde {

	private:
	int _size;
	Zombie* _horde;

	public:
		void announce(void);
		ZombieHorde(int n);
		~ZombieHorde(void);
};

#endif
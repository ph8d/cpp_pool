#include "ZombieHorde.class.hpp"

void ZombieHorde::announce(void) {
	for (int i = 0; i != this->_size; i++) {
		this->_horde[i].announce();
	}
}

ZombieHorde::ZombieHorde(int n) {

	std::string namePool[] = {"Peter", "Grace", "Jeff", "Chump", "Taras", "Lee", "Greg", "Jack", "Andy", "Max"};
	std::string typePool[] = {"Tank", "Regular Zombie", "Crawler", "Regular Zombie", "Runner", "Regular Zombie", "Spitter"};

	if (n > 0) {
		this->_size = n;
		this->_horde = new Zombie[n];
		for(int i = 0; i != n; i++) {
			this->_horde[i].setName(namePool[rand() % 10]);
			this->_horde[i].setType(typePool[rand() % 7]);
		}
	} else {
		std::cout << "Invalid n value, horde will be empty";
	}
	return;
}

ZombieHorde::~ZombieHorde() {
	delete [] this->_horde;
	return;
}
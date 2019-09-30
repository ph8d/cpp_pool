#include <iostream>

#include "Zombie.class.hpp"
#include "ZombieEvent.class.hpp"

int main(void) {

	srand(time(NULL));

	ZombieEvent zombieEvent = ZombieEvent();

	Zombie z1 = Zombie("Tank", "Greg");
	z1.announce();

	zombieEvent.setZombieType("Regular Zombie");

	Zombie* z2 = zombieEvent.newZombie("Jack");
	z2->announce();

	zombieEvent.setZombieType("Crawler");

	Zombie* randomZ = zombieEvent.randomChump();
	randomZ->announce();
	delete randomZ;

	zombieEvent.setZombieType("Runner");

	randomZ = zombieEvent.randomChump();
	randomZ->announce();

	delete z2;
	delete randomZ;
	return 0;
}
#include <iostream>
#include "Zombie.class.hpp"
#include "ZombieEvent.class.hpp"

void ZombieEvent::setZombieType(std::string type) {
	this->_type = type;
}

Zombie* ZombieEvent::newZombie(std::string name) {
	return new Zombie(this->_type, name);
}

Zombie* ZombieEvent::randomChump(void) {
	std::string namePool[] = {"Peter", "Grace", "Jeff", "Chump", "Taras", "Lee"};
	return new Zombie(this->_type, namePool[rand() % 6]);
}

ZombieEvent::ZombieEvent(void) {
	return;
}

ZombieEvent::~ZombieEvent(void) {
	return;
}
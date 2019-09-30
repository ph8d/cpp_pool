#include <iostream>
#include "Zombie.class.hpp"

void Zombie::announce(void) {
	std::cout << "<" + this->_name + " (" + this->_type + ")> " + "Arghhhhhh...." << std::endl;
}

Zombie::Zombie(std::string type, std::string name) {
	this->_type = type;
	this->_name = name;
	return;
}

Zombie::~Zombie(void) {
	std::cout << "<" + this->_name + " (" + this->_type + ")> " + "*died*" << std::endl;
	return;
}

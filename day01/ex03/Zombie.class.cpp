#include <iostream>
#include "Zombie.class.hpp"

void Zombie::announce(void) {
	std::cout << "<" + this->_name + " (" + this->_type + ")> " + "Arghhhhhh...." << std::endl;
}

void Zombie::setType(std::string type) {
	this->_type = type;
}

void Zombie::setName(std::string name) {
	this->_name = name;
}

Zombie::Zombie(void) {
	return;
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

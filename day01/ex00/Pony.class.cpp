#include <iostream>
#include "Pony.class.hpp"

Pony::Pony(std::string name) {
	this->_name = name;
	std::cout << "New Pony with a name " + this->_name + " was born!" << std::endl;
	return;
}

Pony::~Pony(void) {
	std::cout << this->_name + " died." << std::endl;
	return;
}


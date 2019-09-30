#include "Peon.class.hpp"

void Peon::getPolymorphed(void) const {
	std::cout << this->getName() + " has been turned into a pink pony !" << std::endl;
}

Peon & Peon::operator=(Peon const & rhs) {
	this->_name = rhs.getName();
	return *this;
}

Peon::Peon(std::string name): Victim(name) {
	std::cout << "Zog zog." << std::endl;
	return;
}

Peon::Peon(const Peon& toCopy) {
	this->_name = toCopy.getName();
	return;
}

Peon::~Peon(void) {
	std::cout << "Bleuark..." << std::endl;
	return;
}
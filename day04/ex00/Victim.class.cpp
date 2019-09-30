#include "Victim.class.hpp"

void Victim::getPolymorphed(void) const {
	std::cout <<  this->getName() + " has been turned into a cute little sheep !" << std::endl;
}

std::string Victim::getName(void) const {
	return this->_name;
}

Victim & Victim::operator=(Victim const & rhs) {
	this->_name = rhs.getName();
	return *this;
}

Victim::Victim(void) {
	return;
}

Victim::Victim(std::string name): _name(name) {
	std::cout << "Some random victim called " + name + " just popped !" << std::endl;
	return;
}

Victim::Victim(const Victim& toCopy) {
	this->_name = toCopy.getName();
	std::cout << "Some copy of random victim called " + toCopy.getName() + " just popped !" << std::endl;
	return;
}

Victim::~Victim(void) {
	std::cout << "Victim " + this->getName() + " just died for no apparent reason !" << std::endl;
	return;
}

std::ostream & operator<<(std::ostream & o, Victim const & rhs) {
	o << "I'm " + rhs.getName() + " and I like otters !" << std::endl;
	return o;
}
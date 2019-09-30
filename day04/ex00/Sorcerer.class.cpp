#include "Sorcerer.class.hpp"

std::string Sorcerer::getName(void) const {
	return this->_name;
}

std::string Sorcerer::getTitle(void) const {
	return this->_title;
}

void Sorcerer::polymorph(Victim const & victim) const {
	victim.getPolymorphed();
}

Sorcerer & Sorcerer::operator=(Sorcerer const & rhs) {
	this->_name = rhs.getName();
	this->_title = rhs.getTitle();

	return *this;
}

Sorcerer::Sorcerer(std::string name, std::string title): _name(name), _title(title) { 
	std::cout << name + ", " + title + ", " "is born !" << std::endl;
	return;
}

Sorcerer::Sorcerer(const Sorcerer& toCopy) {
	this->_name = toCopy.getName();
	this->_title = toCopy.getTitle();
	std::cout << "Copy of " + toCopy.getName() + ", " + toCopy.getTitle() + ", " " is born !" << std::endl;
	return;
}

Sorcerer::~Sorcerer(void) {
	std::cout << this->_name + ", " + this->_title + ", " "is dead. Consequences will never be the same !" << std::endl;
	return;
}

std::ostream & operator<<(std::ostream & o, Sorcerer const & rhs) {
	o << "I am " + rhs.getName() + ", " + rhs.getTitle() + ", " "and I like ponies !" << std::endl;
	return o;
}
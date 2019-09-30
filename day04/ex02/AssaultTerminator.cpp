#include "AssaultTerminator.class.hpp"

ISpaceMarine* AssaultTerminator::clone(void) const {
	AssaultTerminator* clone = new AssaultTerminator(*this);
	return clone;
}

void AssaultTerminator::rangedAttack(void) const {
	std::cout << "* does nothing *" << std::endl;
}

void AssaultTerminator::meleeAttack(void) const {
	std::cout << "* attacks with chainfists *" << std::endl;
}

void AssaultTerminator::battleCry(void) const {
	std::cout << this->_battleCry << std::endl;
}

AssaultTerminator & AssaultTerminator::operator=(AssaultTerminator const & rhs) {
	this->_battleCry = rhs._battleCry;
	return *this;
}

AssaultTerminator::AssaultTerminator(const AssaultTerminator & toCopy) {
	this->_battleCry = toCopy._battleCry;
}

AssaultTerminator::AssaultTerminator(void): _battleCry("This code is unclean. PURIFY IT !") {
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::~AssaultTerminator(void) {
	std::cout << "I’ll be back ..." << std::endl;
}
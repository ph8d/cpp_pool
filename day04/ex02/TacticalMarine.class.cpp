#include "TacticalMarine.class.hpp"
#include <iostream>

ISpaceMarine* TacticalMarine::clone(void) const{
	ISpaceMarine* clone = new TacticalMarine(*this);
	return clone;
}

void TacticalMarine::battleCry(void) const{
	std::cout << this->_battleCry << std::endl;
}

void TacticalMarine::rangedAttack(void) const{
	std::cout << "* attacks with bolter *" << std::endl;
}

void TacticalMarine::meleeAttack(void) const{
	std::cout << "* attacks with chainsword *" << std::endl;
}

TacticalMarine & TacticalMarine::operator=(TacticalMarine const & rhs) {
	this->_battleCry = rhs._battleCry;
	return *this;
}

TacticalMarine::TacticalMarine(const TacticalMarine & toCopy) {
	this->_battleCry = toCopy._battleCry;
}

TacticalMarine::TacticalMarine(void): _battleCry("For the holy PLOT !") {
	std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::~TacticalMarine(void) {
	std::cout << "Aaargh ..." << std::endl;
}
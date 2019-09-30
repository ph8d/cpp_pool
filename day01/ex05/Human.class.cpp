#include "Human.class.hpp"

std::string Human::identify(void) const {
	return this->_brain.identify();
}

Brain const& Human::getBrain(void) const {
	return _brain;
}

Human::Human(void) {
	return;
}

Human::~Human(void) {
	return;
}
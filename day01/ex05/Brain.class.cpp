
#include <sstream>
#include "Brain.class.hpp"

std::string Brain::identify(void) const {
	std::stringstream ss;
	ss << this;
	return ss.str();
}

Brain::Brain(void) {
	return;
}

Brain::~Brain(void) {
	return;
}
#include "Squad.class.hpp"

int Squad::getCount(void) const {
	return this->_squadSize;
}

ISpaceMarine * Squad::getUnit(int index) const {
	if (index > this->_maxSize) {
		return NULL;
	}
	return this->_marines[index];
}

int Squad::push(ISpaceMarine* marine) {
	if (marine == NULL) {
		return this->_squadSize;
	}

	for (int i = 0; i != this->_squadSize; i++) {
		if (this->_marines[i] == marine) {
			std::cout << "This marine is already in the squad!" << std::endl; 
			return this->_squadSize;
		}
	}

	if (this->_squadSize + 1 <= this->_maxSize) {
		this->_marines[_squadSize] = marine;
		this->_squadSize++;
	} else {
		std::cout << "Squad is full!" << std::endl;
	}
	return this->_squadSize;
}

Squad & Squad::operator=(Squad const & rhs) {
	for (int i = 0; i != this->_squadSize; i++) {
		delete this->_marines[i];
		this->_marines[i] = NULL;
	}

	this->_squadSize = rhs._squadSize;
	for (int i = 0; i != rhs._maxSize; i++) {
		this->_marines[i] = rhs._marines[i];
	}
	return *this;
}

Squad::Squad(const Squad & toCopy): _squadSize(toCopy._squadSize) {
	for (int i = 0; i != toCopy._maxSize; i++) {
		this->_marines[i] = toCopy._marines[i];
	}
}

Squad::Squad(): _squadSize(0) {
	for (int i = 0; i != this->_maxSize; i++) {
		this->_marines[i] = NULL;
	}
}

Squad::~Squad(void) {
	for (int i = 0; i != this->_squadSize; i++) {
		delete this->_marines[i];
	}
}
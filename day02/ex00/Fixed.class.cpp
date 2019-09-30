#include <iostream>
#include "Fixed.class.hpp"

const int Fixed::_bits = 8;

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

Fixed & Fixed::operator=(Fixed const & rhs) {
	std::cout << "Assignation operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return *this;
}

Fixed::Fixed(const Fixed& toCopy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = toCopy;
	return;
}

Fixed::Fixed(void): _value(0) {
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::~Fixed(void) {
	return;
}
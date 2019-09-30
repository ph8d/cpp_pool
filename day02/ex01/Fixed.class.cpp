#include <iostream>
#include <cmath>
#include "Fixed.class.hpp"

const int Fixed::_bits = 8;

float Fixed::toFloat(void) const {
	return ((float)this->_value / (float)(1 << _bits));
}

int Fixed::toInt(void) const {
	return (this->_value >> _bits);
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

int Fixed::getRawBits(void) const {
	return this->_value;
}

Fixed & Fixed::operator=(Fixed const & rhs) {
	std::cout << "Assignation operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return *this;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs) {
	o << rhs.toFloat();
	return o;
}

Fixed::Fixed(const int val) {
	std::cout << "Int constructor called" << std::endl;
	this->_value = val << _bits;
}

Fixed::Fixed(const float val) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = (int)roundf(val * (1 << _bits));
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
	std::cout << "Destructor called" << std::endl;
	return;
}
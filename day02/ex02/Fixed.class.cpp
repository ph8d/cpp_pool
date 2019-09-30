#include <iostream>
#include <cmath>
#include "Fixed.class.hpp"

const int Fixed::_bits = 8;

Fixed & Fixed::min(Fixed & fp1, Fixed & fp2) {
	if (fp1 < fp2) {
		return fp1;
	}
	return fp2;
}

const Fixed & Fixed::min(Fixed const & fp1, Fixed const & fp2) {
	if (fp1 < fp2) {
		return fp1;
	}
	return fp2;
}

Fixed & Fixed::max(Fixed & fp1, Fixed & fp2) {
	if (fp1 > fp2) {
		return fp1;
	}
	return fp2;
}

const Fixed & Fixed::max(Fixed const & fp1, Fixed const & fp2) {
	if (fp1 > fp2) {
		return fp1;
	}
	return fp2;
}

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
	this->_value = rhs.getRawBits();
	return *this;
}

Fixed Fixed::operator+(Fixed const & rhs) const {
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const & rhs) const {
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const & rhs) const {
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const & rhs) const {
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed & Fixed::operator++(void) {
	this->_value++;
	return *this;
}

Fixed & Fixed::operator++(int) {
	Fixed *old = new Fixed(*this);
    this->_value++;
    return *old;
}

Fixed & Fixed::operator--(void) {
	this->_value--;
	return *this;
}

Fixed & Fixed::operator--(int) {
	Fixed *old = new Fixed(*this);
    this->_value--;
    return *old;
}

bool Fixed::operator>(Fixed const & rhs) const {
	return this->getRawBits() > rhs.getRawBits();
}

bool Fixed::operator<(Fixed const & rhs) const {
	return this->getRawBits() < rhs.getRawBits();
}

bool Fixed::operator>=(Fixed const & rhs) const {
	return this->getRawBits() >= rhs.getRawBits();
}

bool Fixed::operator<=(Fixed const & rhs) const {
	return this->getRawBits() <= rhs.getRawBits();
}

bool Fixed::operator==(Fixed const & rhs) const {
	return this->getRawBits() == rhs.getRawBits();
}

bool Fixed::operator!=(Fixed const & rhs) const {
	return this->getRawBits() != rhs.getRawBits();
}

Fixed::Fixed(const int val) {
	this->_value = val << _bits;
}

Fixed::Fixed(const float val) {
	this->_value = (int)roundf(val * (1 << _bits));
}

Fixed::Fixed(const Fixed& toCopy) {
	*this = toCopy;
	return;
}

Fixed::Fixed(void): _value(0) {
	return;
}

Fixed::~Fixed(void) {
	return;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs) {
	o << rhs.toFloat();
	return o;
}
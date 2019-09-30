#include "TypeConverter.class.hpp"

#include <cmath>
#include <limits>
#include <iomanip>


void TypeConverter::_printChar() const {
	std::cout << "char: ";
	char charRepresentation = _literal;
	if (_literal.intOverflow()) {
		std::cout << "imposible" << std::endl;
	}
	else if (isprint(charRepresentation)) {
		std::cout << "'" << charRepresentation << "'" << std::endl;
	} else {
		std::cout << "Non displayable" << std::endl;
	}
}

void TypeConverter::_printInt() const {
	std::cout << "int: ";
	int intRepresentation = _literal;
	if (_literal.intOverflow()) {
		std::cout << "imposible" << std::endl;
	} else {
		std::cout << intRepresentation << std::endl;
	}
}

void TypeConverter::_printFloat() const {
	std::cout << "float: ";
	float floatRepresentation = _literal;
	std::cout << std::fixed;
	std::cout << std::setprecision(1);
	std::cout << floatRepresentation;
	std::cout << "f" << std::endl;
}

void TypeConverter::_printDouble(void) const {
	std::cout << "double: ";
	double doubleRepresentation = _literal;
	std::cout << std::fixed;
	std::cout << std::setprecision(1);
	std::cout << doubleRepresentation << std::endl;
}

void TypeConverter::execute(void) {
		_printChar();
		_printInt();
		_printFloat();
		_printDouble();
}

TypeConverter & TypeConverter::operator=(TypeConverter const & rhs) {
	this->_literal = rhs._literal;

	return *this;
}

TypeConverter::TypeConverter(const TypeConverter & toCopy): _literal(toCopy._literal) {}
TypeConverter::TypeConverter(Literal & literal): _literal(literal) {}
TypeConverter::~TypeConverter(void) {}

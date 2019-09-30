#include "Literal.class.hpp"

std::string Literal::getValue(void) const {
    return this->_value;
}

bool Literal::intOverflow(void) const {
    return _intImposible;
}

Literal & Literal::operator=(Literal const & rhs) {
    this->_value = rhs._value;
    this->_intImposible = rhs._intImposible;
    return *this;
}

Literal::operator char(void) {
    if (_value.length() == 1 && isalpha(_value[0])) {
        return _value[0];
    } else {
        return std::atoi(this->_value.data());
    }
}

Literal::operator int(void) {
    if (_value.length() == 1 && isalpha(_value[0])) {
        return static_cast<int>(_value[0]);
    }
    return std::atoi(this->_value.data());
}

Literal::operator float(void) {
    if (_value.length() == 1 && isalpha(_value[0])) {
        return static_cast<float>(static_cast<int>(_value[0]));
    }
    return atof(this->_value.data());
}

Literal::operator double(void) {
    if (_value.length() == 1 && isalpha(_value[0])) {
        return static_cast<double>(static_cast<int>(_value[0]));
    }
    return atof(this->_value.data());
}

Literal::Literal(void) {}

Literal::Literal(std::string value): _value(value) {
    long tmp = std::atol(_value.data());
    double doubleRepresentation = atof(value.data());


    if (tmp > INT_MAX || tmp < INT_MIN || isnan(doubleRepresentation) || isinf(doubleRepresentation)) {
        this->_intImposible = true;
    } else {
        this->_intImposible = false;
    }
}
Literal::Literal(const Literal & toCopy): _value(toCopy._value), _intImposible(toCopy._intImposible) {}
Literal::~Literal(void) {}

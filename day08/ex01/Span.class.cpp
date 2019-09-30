#include "Span.class.hpp"

void Span::addNumber(int n) {
    if (this->_size + 1 > this->_maxSize) {
        throw SpanIsFullException();
    } else {
        this->_elements.push_back(n);
        this->_size = _elements.size();
    }
}

int Span::shortestSpan(void) {
    if (this->_size < 2) {
        throw NotEnoughElementsException();
    } else {
        std::vector<int>::iterator min = std::min_element(this->_elements.begin(), this->_elements.end());
        std::vector<int>::iterator max = std::max_element(this->_elements.begin(), this->_elements.end());
        return *max - *min;
    }
}

int Span::longestSpan(void) {
    if (this->_size < 2) {
        throw NotEnoughElementsException();
    } else {
        std::vector<int> tmp = this->_elements;

        std::sort(tmp.begin(), tmp.end());

        std::adjacent_difference(tmp.begin(), tmp.end(), tmp.begin());
        tmp.erase(tmp.begin());
        return *std::min_element(tmp.begin(), tmp.end());
    }
}

Span & Span::operator=(Span const & rhs) {
    this->_elements = rhs._elements;
    this->_maxSize = rhs._maxSize;
    this->_size = _elements.size();

    return *this;
}

Span::Span(unsigned int n): _maxSize(n) {
    this->_elements.reserve(n);
    this->_size = this->_elements.size();
}

Span::Span(const Span & toCopy) {
    this->_elements = toCopy._elements;
    this->_maxSize = toCopy._maxSize;
    this->_size = _elements.size();
}

Span::Span(void) {};
Span::~Span(void) {}



const char* Span::SpanIsFullException::what() const throw() {
	return ("span is full");
}

Span::SpanIsFullException & Span::SpanIsFullException::operator=(SpanIsFullException const & rhs) {
	(void)rhs;
	return *this;
}

Span::SpanIsFullException::SpanIsFullException(const SpanIsFullException & toCopy) {
	*this = toCopy;
}

Span::SpanIsFullException::SpanIsFullException(void) {}
Span::SpanIsFullException::~SpanIsFullException(void) throw() {}



const char* Span::NotEnoughElementsException::what() const throw() {
	return ("not enough elements");
}

Span::NotEnoughElementsException & Span::NotEnoughElementsException::operator=(NotEnoughElementsException const & rhs) {
	(void)rhs;
	return *this;
}

Span::NotEnoughElementsException::NotEnoughElementsException(const NotEnoughElementsException & toCopy) {
	*this = toCopy;
}

Span::NotEnoughElementsException::NotEnoughElementsException(void) {}
Span::NotEnoughElementsException::~NotEnoughElementsException(void) throw() {}
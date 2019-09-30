#ifndef SPAN_CLASS_HPP
# define SPAN_CLASS_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <numeric>

class Span {

public:
    void addNumber(int n);
    int shortestSpan(void);
    int longestSpan(void);

    Span & operator=(Span const & rhs);

    Span(unsigned int n);
    Span(const Span & toCopy);
    ~Span(void);

private:
    std::vector<int> _elements;
    std::vector<int>::size_type _size;
    unsigned int _maxSize;

    Span(void);

    class SpanIsFullException: public std::exception {
		public:
			const char* what() const throw();
			SpanIsFullException & operator=(SpanIsFullException const & rhs);
			SpanIsFullException(const SpanIsFullException & toCopy);
			SpanIsFullException(void);
			~SpanIsFullException(void) throw();
	};

    class NotEnoughElementsException: public std::exception {
		public:
			const char* what() const throw();
			NotEnoughElementsException & operator=(NotEnoughElementsException const & rhs);
			NotEnoughElementsException(const NotEnoughElementsException & toCopy);
			NotEnoughElementsException(void);
			~NotEnoughElementsException(void) throw();
	};

};

#endif
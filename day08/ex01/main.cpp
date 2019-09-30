#include "Span.class.hpp"

#include <iostream>


int main() {
    Span sp = Span(5);

    sp.addNumber(1);
    sp.addNumber(3);
    sp.addNumber(8);
    sp.addNumber(1001);
    sp.addNumber(1000);

    try {
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        sp.addNumber(5);
    } catch (std::exception & e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        Span excp = Span(1);
        excp.addNumber(1);
        excp.longestSpan();
    } catch (std::exception & e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
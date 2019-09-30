#include "Array.class.hpp"
#include <iostream>

int main(void) {

    Array<int> a(5);
    std::cout << a.size() << std::endl;

    std::cout << a[0] << std::endl;

    a[0] = 42;

    std::cout << a[0] << std::endl;

    std::cout << a.size() << std::endl;
    
    std::cout << std::endl;


    std::cout << std::endl << "Copying:" << std::endl;
    Array<int> b(a);

    for (size_t i = 0; i != a.size(); i++) {
        std::cout << a[i] << " - " << b[i] << std::endl;
    }

    std::cout << std::endl;
    a[0] = 1;

    for (size_t i = 0; i != a.size(); i++) {
        std::cout << a[i] << " - " << b[i] << std::endl;
    }

    std::cout << std::endl << "Assign operator: " << std::endl;
    Array<int> c(3);

    c = b;

    for (size_t i = 0; i != c.size(); i++) {
        std::cout << b[i] << " - " << c[i] << std::endl;
    }

    try {
        std::cout << a[1000000000] << std::endl;
    } catch (std::exception &e) {
        std::cout << std::endl << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
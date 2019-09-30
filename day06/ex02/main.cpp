
#include <iostream>

class Base { public: virtual ~Base(void) {}; };
class A: public Base {};
class B: public Base {};
class C: public Base {};


void identify_from_pointer( Base * p ) {
    std::cout << "by pointer:   ";
    if (dynamic_cast<A *>(p) != NULL) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B *>(p) != NULL) {
        std::cout << "B" << std::endl;
    } else {
        std::cout << "C" << std::endl;
    }
}

void identify_from_reference( Base & p ) {
    std::cout << "by reference: ";
    if (dynamic_cast<A *>(&p) != NULL) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B *>(&p) != NULL) {
        std::cout << "B" << std::endl;
    } else {
        std::cout << "C" << std::endl;
    }
}

Base * generate(void) {
    int n = rand() % 3;

    if (n == 0) {
        return new A();
    } else if (n == 1) {
        return new B();
    } else {
        return new C();
    }
}

int main(void) {
    srand(clock());

    Base * randInstance;

    randInstance = generate();
    identify_from_pointer(randInstance);
    identify_from_reference(*randInstance);

    delete randInstance;
    return 0;
}
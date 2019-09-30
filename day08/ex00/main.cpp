
#include "easyfind.hpp"

int main(void) {

    std::vector<char> vec;

    
    vec.push_back('a');
    vec.push_back('b');
    vec.push_back('c');
    vec.push_back('d');
    vec.push_back('e');

    std::vector<char>::iterator i = easyifnd(vec, 'e');

    std::cout << *i << std::endl;

    i = easyifnd(vec, 'u');

    std::cout << *i << std::endl;

    return 0;
}
#include <iostream>

template <typename T>
void printThis(T const & thing) {
    std::cout << thing << std::endl;
}

template <typename A, typename B, typename C>
void iter(A* arr, size_t size, B (*f)(C &)) {
    for (int i = 0; i != size; i++) {
        f(arr[i]);
    }
}

int main(void) {

    int intArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    float floatArr[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
    char charArr[] = {65, 66, 67, 68, 69, 70, 71, 72, 73};

    iter(intArr, 9, &printThis<int>);
    std::cout << std::endl;

    iter(floatArr, 9, &printThis<float>);
    std::cout << std::endl;

    iter(charArr, 9, &printThis<char>);
    std::cout << std::endl;

    return 0;
}
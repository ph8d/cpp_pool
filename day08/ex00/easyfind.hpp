#ifndef EASYFIND_CLASS_HPP
# define EASYFIND_CLASS_HPP

# include <iostream>
# include <vector> 

template <typename T>
typename T::iterator easyifnd(T & container, int toFind) {
    return std::find(container.begin(), container.end(), toFind);
}

#endif
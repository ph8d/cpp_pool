#ifndef MUTANTSTACK_CLASS_HPP
# define MUTANTSTACK_CLASS_HPP

# include <stack>
# include <iterator>

template <typename T>
class MutantStack: public std::stack<T> {

public:
    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin(void) { return this->c.begin(); };
    iterator end(void) { return this->c.end(); };

    MutantStack & operator=(MutantStack const & rhs) { std::stack<T>::operator=(rhs); }

    MutantStack(const MutantStack & toCopy) { *this = toCopy; };
    MutantStack(void) {};
    ~MutantStack(void) {};

};

#endif
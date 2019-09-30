#ifndef ARRAY_CLASS_HPP
# define ARRAY_CLASS_HPP

# include <iostream>

template <typename T>
class Array {

public:
    size_t size(void) const {
        return this->_size;
    }

    Array<T> & operator=(Array const & rhs) {
        delete[] this->_elements;
        this->_size = rhs.size();
        this->_elements = new T[rhs.size()];

        for (size_t i = 0; i != rhs.size(); i++) {
            this->_elements[i] = rhs[i];
        }

        return *this;
    }

    T & operator[](size_t n) const {
        if (n > _size) {
            throw OutOfRangeException();
        }
        return this->_elements[n];
    }

    Array<T>(void) {
        this->_size = 1;
        this->_elements = new T[0];
        this->_elements[0] = 0;
    }

    Array<T>(unsigned int n) {
        this->_size = n;
        this->_elements = new T[n];
        for (size_t i = 0; i != n; i++) {
            this->_elements[i] = 0;
        }
    }

    Array<T>(const Array<T> & toCopy) {
        this->_size = toCopy.size();
        this->_elements = new T[toCopy.size()];

        for (size_t i = 0; i != toCopy.size(); i++) {
            this->_elements[i] = toCopy[i];
        }
    }

    ~Array<T>(void) {
        delete[] this->_elements;
    }

    class OutOfRangeException: public std::exception {
		public:
			const char* what() const throw() {
                return ("Out of range");
            }

            OutOfRangeException & operator=(OutOfRangeException const & rhs) {
                (void)rhs;
                return *this;
            }

            OutOfRangeException(const OutOfRangeException & toCopy) {
                *this = toCopy;
            }

            OutOfRangeException(void) {}
            ~OutOfRangeException(void) throw() {}
	};


private:
    T * _elements;
    size_t _size;

};

#endif

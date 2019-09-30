#ifndef LITERAL_CLASS_HPP
# define LITERAL_CLASS_HPP

# include <iostream>
# include <limits>
# include <cmath>

class Literal {

    std::string _value;
    bool _intImposible;

public:

    std::string getValue(void) const;
    bool intOverflow(void) const;

    operator char(void);
    operator int(void);
    operator float(void);
    operator double(void);

    Literal & operator=(Literal const & rhs);

    Literal(void);
    Literal(std::string value);
    Literal(const Literal & toCopy);
    ~Literal(void);

};

#endif

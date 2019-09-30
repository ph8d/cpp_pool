#ifndef UTILITIES_CLASS_HPP
# define UTILITIES_CLASS_HPP

# include <iostream>

class Utilities {

public:
    std::string getCommandOutput(const char * cmd);

    Utilities & operator=(Utilities const & rhs);

    Utilities(void);
    Utilities(const Utilities & toCopy);
    ~Utilities(void);

};

#endif
#ifndef USERMODULE_CLASS_HPP
# define USERMODULE_CLASS_HPP

# include "IMonitorModule.class.hpp"
# include <unistd.h>
# include <iostream>

class UserModule: public IMonitorModule {

private:
    std::string _userName;
    std::string _hostName;

public:
    void update(void);
    std::string getUserName(void) const;
    std::string getHostName(void) const;

    UserModule & operator=(UserModule const & rhs);

    UserModule(void);
    UserModule(const UserModule & toCopy);
    ~UserModule(void);
};

#endif
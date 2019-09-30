#ifndef OSINFOMODULE_CLASS_HPP
# define OSINFOMODULE_CLASS_HPP

# include "IMonitorModule.class.hpp"
# include "Utilities.class.hpp"
# include <iostream>
# include <sys/utsname.h>


class OSInfoModule: public IMonitorModule {

private:
    std::string _OSName;
    std::string _OSVersion;
    std::string _OSBuild;
    struct utsname _kernelInfo;

    std::string _exec(const char * cmd);

public:
    void update(void);
    std::string getName(void) const;
    std::string getVersion(void) const;
    std::string getBuild(void) const;
    std::string getKernelV(void) const;

    OSInfoModule & operator=(OSInfoModule const & rhs);

    OSInfoModule(void);
    OSInfoModule(const OSInfoModule & toCopy);
    ~OSInfoModule(void);


};

#endif
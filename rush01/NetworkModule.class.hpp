#ifndef NETWORKMODULE_CLASS_HPP
# define NETWORKMODULE_CLASS_HPP

# include "IMonitorModule.class.hpp"
# include "Utilities.class.hpp"
# include <iostream>

class NetworkModule: public IMonitorModule {

private:
    std::string _packetsIn;
    std::string _packetsOut;

public:
    std::string getInPackets(void) const;
    std::string getOutPackets(void) const;

    NetworkModule & operator=(NetworkModule const & rhs);

    void update(void);
    NetworkModule(const NetworkModule & toCopy);
    NetworkModule(void);
    ~NetworkModule(void);

};

#endif
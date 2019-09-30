#ifndef MEMORYMODULE_CLASS_HPP
# define MEMORYMODULE_CLASS_HPP

# include "IMonitorModule.class.hpp"
# include <sys/sysctl.h>

class MemoryModule: public IMonitorModule  {

private:
    int _pageSize;
    
    int _totalRAM;
    int _usedRAM;
    int _freeRAM;


public:
    void update(void);

    int getTotalRAM(void) const;
    int getUsedRAM(void) const;
    int getFreeRAM(void) const;

    MemoryModule & operator=(MemoryModule const & rhs);

    MemoryModule(void);
    MemoryModule(const MemoryModule & toCopy);
    ~MemoryModule(void);

};

#endif
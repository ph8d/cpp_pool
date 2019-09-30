#ifndef MONITOR_CLASS_HPP
# define MONITOR_CLASS_HPP

# include "UserModule.class.hpp"
# include "OSInfoModule.class.hpp"
# include "TimeModule.class.hpp"
# include "CPUModule.class.hpp"
# include "MemoryModule.class.hpp"
# include "NetworkModule.class.hpp"
# include "NcursesMode.class.hpp"
# include "MonitorDataTypes.hpp"

class SysMonitor {

private:
    UserModule      _userModule;
    OSInfoModule    _osModule;
    TimeModule      _timeModule;
    CPUModule       _cpuModule;
    MemoryModule    _memoryModule;
    NetworkModule   _networkModule;

    StaticData     _staticData;
    DynamicData     _dynamicData;

    void _updateData(void);
    void _fetchDynamicData(void);
    void _fetchStaticData(void);

public:
    void runNcursesMode(void);
    void runGraphicalMode(void);

    SysMonitor & operator=(SysMonitor const & rhs);

    SysMonitor(const SysMonitor & toCopy);
    SysMonitor(void);    
    ~SysMonitor(void);

};

#endif
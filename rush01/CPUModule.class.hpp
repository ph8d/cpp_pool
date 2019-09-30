#ifndef CPUSTATUS_CLASS_HPP
# define CPUSTATUS_CLASS_HPP

# include <stdio.h>
# include <unistd.h>
# include <mach/mach_host.h>
# include <mach/processor_info.h>
# include <iostream>
# include <sys/sysctl.h>
# include "IMonitorModule.class.hpp"

struct Core {
    unsigned long long int usertime;
    unsigned long long int nicetime;
    unsigned long long int systemtime;
    unsigned long long int idletime;
    float usage;

    unsigned long long int used() {
        return usertime + nicetime + systemtime;
    }

    unsigned long long int total() {
        return usertime + nicetime + systemtime + idletime;
    }
};

class CPUModule: public IMonitorModule {

private:
    float _usage;
    unsigned int _cpuCoreCount;
    processor_cpu_load_info_t _cpuLoad;
    mach_msg_type_number_t _cpuMsgCount;
    Core* _cores;

    std::string _cpuModel;

    void _updateCpuInfo(void);
    Core * _getCores(void);

public:
    float getUsage(void) const;
    float getCoreUsage(unsigned int const core) const;
    std::string getModel(void) const;
    unsigned int getCoreCount(void) const;
    void update(void);

    CPUModule & operator=(CPUModule const & rhs);

    CPUModule(const CPUModule & toCopy);
    CPUModule(void);
    ~CPUModule(void);

};

#endif
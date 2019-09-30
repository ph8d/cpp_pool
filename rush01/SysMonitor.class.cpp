#include "SysMonitor.class.hpp"

void SysMonitor::_fetchDynamicData(void) {
    this->_dynamicData.currentTime = _timeModule.getCurrentTime();
    this->_dynamicData.totalRAM = _memoryModule.getTotalRAM();
    this->_dynamicData.usedRAM = _memoryModule.getUsedRAM();
    this->_dynamicData.freeRAM = _memoryModule.getFreeRAM();
    this->_dynamicData.coreUsage[0] = _cpuModule.getCoreUsage(0);
    this->_dynamicData.coreUsage[1] = _cpuModule.getCoreUsage(1);
    this->_dynamicData.coreUsage[2] = _cpuModule.getCoreUsage(2);
    this->_dynamicData.coreUsage[3] = _cpuModule.getCoreUsage(3);
    this->_dynamicData.netPacketsIn = _networkModule.getInPackets();
    this->_dynamicData.netPacketsOut = _networkModule.getOutPackets();
}

void SysMonitor::_fetchStaticData(void) {
    this->_staticData.userName = _userModule.getUserName();
    this->_staticData.hostName = _userModule.getHostName();
    this->_staticData.osName = _osModule.getName();
    this->_staticData.osVersion = _osModule.getVersion();
    this->_staticData.osBuild = _osModule.getBuild();
    this->_staticData.kernelVersion = _osModule.getKernelV();
}

void SysMonitor::_updateData(void) {
    this->_timeModule.update();
    this->_cpuModule.update();
    this->_memoryModule.update();
    this->_networkModule.update();
}

void SysMonitor::runNcursesMode(void) {
    NcursesMode ncurses;

    while (42) {
        sleep(1);
        _updateData();
        _fetchDynamicData();
        ncurses.draw(this->_staticData, this->_dynamicData);
        if (getch() == 113) {
            endwin();
			system("reset");
			return;
        }
        refresh();
        erase();
    }
}

SysMonitor & SysMonitor::operator=(SysMonitor const & rhs) {
    this->_userModule = rhs._userModule;
    this->_osModule = rhs._osModule;
    this->_timeModule = rhs._timeModule;
    this->_cpuModule = rhs._cpuModule;
    this->_memoryModule = rhs._memoryModule;
    this->_networkModule = rhs._networkModule;
    this->_staticData = rhs._staticData;
    this->_dynamicData = rhs._dynamicData;

    return *this;
}

void SysMonitor::runGraphicalMode(void) {

}

SysMonitor::SysMonitor(const SysMonitor & toCopy) {
    *this = toCopy;
}

SysMonitor::SysMonitor(void) {
    this->_fetchStaticData();    
}

SysMonitor::~SysMonitor(void) {}
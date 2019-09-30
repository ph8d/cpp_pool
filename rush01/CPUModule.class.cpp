#include "CPUModule.class.hpp"

void CPUModule::_updateCpuInfo(void) {
    host_processor_info(
        mach_host_self(),
        PROCESSOR_CPU_LOAD_INFO,
        &this->_cpuCoreCount,
        (processor_info_array_t *) &_cpuLoad,
        &_cpuMsgCount);
}

Core * CPUModule::_getCores(void) {
    this->_updateCpuInfo();
    Core * cores = new Core[this->_cpuCoreCount];
    for (size_t i = 0; i != this->_cpuCoreCount; i++) {
        cores[i].usertime = _cpuLoad[i].cpu_ticks[CPU_STATE_USER];
        cores[i].nicetime = _cpuLoad[i].cpu_ticks[CPU_STATE_NICE];
        cores[i].systemtime = _cpuLoad[i].cpu_ticks[CPU_STATE_SYSTEM];
        cores[i].idletime = _cpuLoad[i].cpu_ticks[CPU_STATE_IDLE];
        cores[i].usage = 0;
    }

    return cores;
}

float CPUModule::getUsage(void) const {
    return this->_usage;
}

float CPUModule::getCoreUsage(unsigned int const core) const {
    if (core >= this->_cpuCoreCount) {
        return 0;
    }
    return this->_cores[core].usage;
}

std::string CPUModule::getModel(void) const {
    return this->_cpuModel;
}

unsigned int CPUModule::getCoreCount(void) const {
    return this->_cpuCoreCount;
}

void CPUModule::update(void) {
    Core * updatedCores = _getCores();
    unsigned long long int used = 0;
    unsigned long long int total = 0;
    float totalUsage = 0;

    for (size_t i = 0; i != this->_cpuCoreCount; i++) {
        used = updatedCores[i].used() - this->_cores[i].used();
        total = updatedCores[i].total() - this->_cores[i].total();
        updatedCores[i].usage = (float)used / (float)total * 100.0f;
        totalUsage += (float)used / (float)total * 100.0f;
    }

    delete [] this->_cores;
    this->_cores = updatedCores;

    this->_usage = totalUsage / this->_cpuCoreCount;
}

CPUModule & CPUModule::operator=(CPUModule const & rhs) {
    this->_usage = rhs._usage;
    this->_cpuCoreCount = rhs._cpuCoreCount;
    this->_cpuLoad = rhs._cpuLoad;
    this->_cpuMsgCount = rhs._cpuMsgCount;
    this->_cpuModel = rhs._cpuModel;

    return *this;
}

CPUModule::CPUModule(const CPUModule & toCopy) {
    *this = toCopy;
}

CPUModule::CPUModule(void) {
    this->_updateCpuInfo();
    this->_cores = _getCores();

    char buff[100];
    size_t buffSize = sizeof(buff);
    sysctlbyname("machdep.cpu.brand_string", &buff, &buffSize, NULL, 0);

    this->_cpuModel.assign(buff);
}

CPUModule::~CPUModule(void) {
    delete [] this->_cores;
}
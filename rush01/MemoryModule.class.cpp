#include "MemoryModule.class.hpp"

void MemoryModule::update(void) {
    int freePageCount;
    size_t sizeOfInt = sizeof(freePageCount);

    sysctlbyname("vm.page_free_count", &freePageCount, &sizeOfInt, NULL, 0);

    this->_freeRAM = (freePageCount * this->_pageSize) / 1048576;
    this->_usedRAM = this->_totalRAM - this->_freeRAM;
}

MemoryModule & MemoryModule::operator=(MemoryModule const & rhs) {
    this->_pageSize = rhs._pageSize;
    this->_totalRAM = rhs._totalRAM;
    this->_usedRAM = rhs._usedRAM;
    this->_freeRAM = rhs._freeRAM;

    return *this;
}

int MemoryModule::getTotalRAM(void) const {
    return this->_totalRAM;
}

int MemoryModule::getUsedRAM(void) const {
    return this->_usedRAM;
}

int MemoryModule::getFreeRAM(void) const {
    return this->_freeRAM;
}

MemoryModule::MemoryModule(const MemoryModule & toCopy) {
    *this = toCopy;
}

MemoryModule::MemoryModule(void) {
    unsigned long totalBytes;
    int pageSize;

    size_t sizeOfULong = sizeof(totalBytes);
    size_t sizeOfUInt = sizeof(pageSize);

    sysctlbyname("hw.memsize", &totalBytes, &sizeOfULong, NULL, 0);
    sysctlbyname("vm.pagesize", &pageSize, &sizeOfUInt, NULL, 0);
    
    this->_totalRAM = (totalBytes / 1024 / 1024);
    this->_pageSize = pageSize;
}
MemoryModule::~MemoryModule(void) {}
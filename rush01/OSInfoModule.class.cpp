#include "OSInfoModule.class.hpp"

void OSInfoModule::update() {
    Utilities utils;
    this->_OSName = utils.getCommandOutput("sw_vers -productName");
    this->_OSVersion = utils.getCommandOutput("sw_vers -productVersion");
    this->_OSBuild = utils.getCommandOutput("sw_vers -buildVersion");
    uname(&this->_kernelInfo);
}

std::string OSInfoModule::getName(void) const {
    return this->_OSName;
}

std::string OSInfoModule::getVersion(void) const {
    return this->_OSVersion;
}

std::string OSInfoModule::getBuild(void) const {
    return this->_OSBuild;
}

std::string OSInfoModule::getKernelV(void) const {
    return this->_kernelInfo.release;
}


OSInfoModule & OSInfoModule::operator=(OSInfoModule const & rhs) {
    this->_OSName = rhs._OSName;
    this->_OSVersion = rhs._OSVersion;
    this->_OSBuild = rhs._OSBuild;
    this->_kernelInfo = rhs._kernelInfo;

    return *this;
}

OSInfoModule::OSInfoModule(const OSInfoModule & toCopy) {
    this->_OSName = toCopy._OSName;
    this->_OSVersion = toCopy._OSVersion;
    this->_OSBuild = toCopy._OSBuild;
    this->_kernelInfo = toCopy._kernelInfo;
}

OSInfoModule::OSInfoModule() {
    this->update();
}

OSInfoModule::~OSInfoModule() {}

#include "NetworkModule.class.hpp"

void NetworkModule::update(void) {
    Utilities utils;

    std::string topOutput = utils.getCommandOutput("top -n 0 -l 1");
    
    topOutput = topOutput.data() + topOutput.find("packets:");
    topOutput = topOutput.data() + topOutput.find(" ") + 1;
    topOutput = topOutput.substr(0, topOutput.find_first_of("."));

    this->_packetsIn = topOutput.substr(0, topOutput.find(" "));
    topOutput = topOutput.data() + topOutput.find(", ") + 2;
    this->_packetsOut = topOutput.substr(0, topOutput.find_last_of(" "));
}

std::string NetworkModule::getInPackets(void) const {
    return this->_packetsIn;
}

std::string NetworkModule::getOutPackets(void) const {
    return this->_packetsOut;
}

NetworkModule & NetworkModule::operator=(NetworkModule const & rhs) {
    this->_packetsIn = rhs._packetsIn;
    this->_packetsOut = rhs._packetsOut;

    return *this;
}

NetworkModule::NetworkModule(const NetworkModule & toCopy) {
    *this = toCopy;
}

NetworkModule::NetworkModule(void) {}
NetworkModule::~NetworkModule(void) {}
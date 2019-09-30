#include "TimeModule.class.hpp"

char * TimeModule::getCurrentTime(void) const {
    return asctime(this->_timeInfo);
}

void TimeModule::update(void) {
    time(&this->_rawTime);
    this->_timeInfo = localtime(&this->_rawTime);
}

TimeModule & TimeModule::operator=(TimeModule const & rhs) {
    this->_rawTime = rhs._rawTime;
    this->_timeInfo = rhs._timeInfo;

    return *this;
}

TimeModule::TimeModule(const TimeModule & toCopy) {
    this->_rawTime = toCopy._rawTime;
    this->_timeInfo = toCopy._timeInfo;
}

TimeModule::TimeModule(void) {}
TimeModule::~TimeModule(void) {}
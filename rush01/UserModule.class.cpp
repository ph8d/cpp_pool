#include "UserModule.class.hpp"

void UserModule::update(void) {
    char hostname[_SC_HOST_NAME_MAX];
    char username[_SC_LOGIN_NAME_MAX];

    gethostname(hostname, _SC_HOST_NAME_MAX);
    getlogin_r(username, _SC_LOGIN_NAME_MAX);

    this->_userName.assign(username);
    this->_hostName.assign(hostname);
}

std::string UserModule::getUserName(void) const {
    return this->_userName;
}

std::string UserModule::getHostName(void) const {
    return this->_hostName;
}

UserModule & UserModule::operator=(UserModule const & rhs) {
    this->_userName = rhs._userName;
    this->_hostName = rhs._hostName;

    return *this;
}

UserModule::UserModule(const UserModule & toCopy) {
    *this = toCopy;
}

UserModule::UserModule(void) {
    this->update();
}

UserModule::~UserModule(void) {}
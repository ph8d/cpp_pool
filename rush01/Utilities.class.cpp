#include "Utilities.class.hpp"

std::string Utilities::getCommandOutput(const char * cmd) {
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen(cmd, "r");
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    try {
        while (!feof(pipe)) {
            if (fgets(buffer, 128, pipe) != NULL) {
                result += buffer;                
            }
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}

Utilities & Utilities::operator=(Utilities const & rhs) {
    static_cast<void>(rhs);
    return *this;
}

Utilities::Utilities(const Utilities & toCopy) {
    *this = toCopy;
}

Utilities::Utilities(void) {}
Utilities::~Utilities(void) {}
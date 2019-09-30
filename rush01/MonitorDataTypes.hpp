#ifndef MONITORDATATYPES_HPP
# define MONITORDATATYPES_HPP

# include <string>

typedef struct sMonitorStaticData {
    std::string userName;
    std::string hostName;
    std::string osName;
    std::string osVersion;
    std::string osBuild;
    std::string kernelVersion;
} StaticData;

typedef struct sMonitorDynamicData {
    int totalRAM;
    int usedRAM;
    int freeRAM;
    char * currentTime;
    float coreUsage[4];
    std::string netPacketsIn;
    std::string netPacketsOut;
} DynamicData;

#endif
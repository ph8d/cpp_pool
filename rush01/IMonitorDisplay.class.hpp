#ifndef IMONITORDISPLAY_CLASS_HPP
# define IMONITORDISPLAY_CLASS_HPP

# include "MonitorDataTypes.hpp"

class IMonitorDisplay {

public:
    virtual void draw(StaticData, DynamicData) = 0;

};

#endif
#ifndef GRAPHICALMODE_CLASS_HPP
# define GRAPHICALMODE_CLASS_HPP

# include "IMonitorDisplay.class.hpp"

class GraphicalMode: public IMonitorDisplay {

public:
    void draw(StaticData staticData, DynamicData dynamicData);

    GraphicalMode & operator=(GraphicalMode const & rhs);

    GraphicalMode(void);
    GraphicalMode(const GraphicalMode & toCopy);
    ~GraphicalMode(void);

};

#endif
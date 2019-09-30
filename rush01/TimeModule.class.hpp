#ifndef TIMEMODULE_CLASS_HPP
# define TIMEMODULE_CLASS_HPP

# include "IMonitorModule.class.hpp"
# include <time.h>

class TimeModule: public IMonitorModule {

private:
    time_t _rawTime;
    struct tm * _timeInfo;

public:
    char * getCurrentTime(void) const;
    void update(void);

    TimeModule & operator=(TimeModule const & rhs);

    TimeModule(void);
    TimeModule(const TimeModule & toCopy);
    ~TimeModule(void);

};

#endif
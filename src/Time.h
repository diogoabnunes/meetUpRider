#ifndef MEETUPRIDER_TIME_H
#define MEETUPRIDER_TIME_H

#include <string>
#include "vector"
#include "utils.h"
using namespace std;

class Time {
private:
    int hour;
    int minutes;

public:
    Time(int hour, int minutes);
    Time();
    Time(string &t);

    int getHour() const;
    void setHour(int hour);
    int getMinutes() const;
    void setMinutes(int minutes);

    bool operator<(const Time &t);

};

#endif //MEETUPRIDER_TIME_H

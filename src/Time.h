//
// Created by clara on 08/05/2020.
//

#ifndef MEETUPRIDER_TIME_H
#define MEETUPRIDER_TIME_H
#include <string>
#include "vector"
#include "utils.h"
using namespace std;

class Time {
public:
    Time(int hour, int minutes);

    Time();

    Time(string& t) ;

    int getHour() const;

    void setHour(int hour);

    int getMinutes() const;

    void setMinutes(int minutes);

private:
    int hour;
    int minutes;
};


#endif //MEETUPRIDER_TIME_H

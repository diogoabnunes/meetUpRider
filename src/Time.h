#ifndef MEETUPRIDER_TIME_H
#define MEETUPRIDER_TIME_H
#pragma once
#include <string>
#include "vector"
#include "utils.h"
#include <cmath>
using namespace std;

class Time {
private:
    int hour;
    int minutes;
    int seconds;
public:
    int getSeconds() const;

    void setSeconds(int seconds);

public:
    Time(int hour, int minutes);
    Time();
    Time(string &t);

    Time(int hour, int minutes, int seconds);

    int getHour() const;
    void setHour(int hour);
    int getMinutes() const;
    void setMinutes(int minutes);
    Time add(Time t);
    bool operator<(const Time &rhs) const ;
    bool operator<=(const Time &rhs) const ;
    Time operator+(const Time &rhs)const;

};


#endif //MEETUPRIDER_TIME_H

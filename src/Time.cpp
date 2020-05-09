//
// Created by clara on 08/05/2020.
//

#include "Time.h"

int Time::getHour() const {
    return hour;
}

void Time::setHour(int hour) {
    Time::hour = hour;
}

int Time::getMinutes() const {
    return minutes;
}

void Time::setMinutes(int minutes) {
    Time::minutes = minutes;
}

Time::Time(int hour, int minutes) : hour(hour), minutes(minutes) {}

Time::Time() {hour=-1; minutes=-1;}

Time::Time(string& t) {
    auto time=split(t,"h");
    hour=stoi(time[0]);
    minutes=stoi(time[1]);
}



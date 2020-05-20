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

Time::Time() {
    hour=-1;
    minutes=-1;
}

Time::Time(string &t) {
    auto time=split(t,"h");
    hour=stoi(time[0]);
    minutes=stoi(time[1]);
}

bool Time::operator<(const Time &t) {
    int t1=this->getHour()*100+this->getMinutes();
    int t2=t.getHour()*100+t.getMinutes();
    return t1<t2;
}

ostream &operator<<(ostream &os, const Time &t) {
    os << t.hour << "h" << t.minutes;
}



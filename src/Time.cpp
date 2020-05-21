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

Time::Time(int hour, int minutes, int seconds) : hour(hour), minutes(minutes), seconds(seconds) {}

Time::Time() {
    hour=-1;
    minutes=-1;
    seconds=0;
}


Time::Time(double t) {
    auto decimal=t-floor(t);
    int s=floor(decimal*60);
    s=s%60;
    int min=(int)floor(t)+(s/60);
    int h=min/60;
    h=h%24;
    hour=h;
    seconds=s;
    minutes=min;
}


Time::Time(string &t) {
    auto time=split(t,"h");
    hour=stoi(time[0]);
    minutes=stoi(time[1]);
    seconds=0;
}

Time Time::add(Time t) {
    int min= minutes+t.getMinutes();
    int h=hour+t.getHour()+min/60;
    min=min%60;
    h=h%60;
    return {h,min};
}

bool Time::operator<(const Time &rhs) const {
    if(hour==rhs.hour){
        if(minutes==rhs.minutes)return seconds==rhs.seconds;
        else return minutes<rhs.minutes;
    }
    else return hour<rhs.hour;
}

bool Time::operator<=(const Time &rhs) const {
    if(hour==rhs.hour){
        if(minutes==rhs.minutes)return seconds==rhs.seconds;
        else return minutes<=rhs.minutes;
    }
    else return hour<=rhs.hour;
}

Time Time::operator+(const Time &rhs) const {
    int s=seconds+rhs.seconds;

    int min= minutes+rhs.getMinutes()+(s/60);
    int h=hour+rhs.getHour()+min/60;
    min=min%60;
    s=s%60;
    h=h%24;
    return {h,min,s};
}

int Time::getSeconds() const {
    return seconds;
}

void Time::setSeconds(int seconds) {
    Time::seconds = seconds;
}

bool Time::operator>(const Time &rhs) const {
    return !(*this <=rhs);
}

bool Time::operator>=(const Time &rhs) const {
    return !(*this <rhs);
}

ostream& operator<<(ostream& os, const Time& t)
{
    os << t.getHour() << 'h' << t.getMinutes() << 'm' << t.getSeconds()<<'s';
    return os;
}
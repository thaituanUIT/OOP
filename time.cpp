#include <iostream>
#include <string>
using namespace std;

class Time {
    private:
        int hrs;
        int mins;
        int secs;
    public:
        Time();
        Time(int, int, int);
        void SetTime(int, int, int);
        Time operator++();
        Time operator++(int);
        Time operator--();
        Time operator--(int);
        bool operator>(Time const&) const;
        bool operator<(Time const&) const;
        int compare(Time const&) const;
        void DisplayTime();
};

Time::Time()
{
    hrs = 0;
    mins = 0;
    secs = 0;
}

Time::Time(int h, int m, int s) : hrs(h), mins(m), secs(s)
{}

void Time::SetTime(int h, int m, int s)
{
    hrs = h;
    mins = m;
    secs = s;
}

Time Time::operator++() {
    ++secs;
    if (secs >= 60){
        ++mins;
        secs -= 60;
    }
    if (mins >= 60){
        ++hrs;
        mins -= 60;
    }
    if (hrs >= 24) {
        hrs -= 24;
    }
    return *this;
}

Time Time::operator++(int) {
    Time tmp(*this);
    ++(*this);
    return tmp;
}

Time Time::operator--() {
    --secs;
    if (secs == -1) {
        --mins;
        secs += 60;
    }
    if (mins == -1) {
        --hrs;
        mins += 60;
    }
    if (hrs == -1) {
        hrs += 24;
    }
    return *this;
}

Time Time::operator--(int) {
    Time tmp(*this);
    --(*this);
    return tmp;
}

int Time::compare(Time const& other) const {
    int result = hrs - other.hrs;
    if (result == 0) {
        result = mins - other.mins;
        if (result == 0)
            result = secs - other.secs;
    }
    return result;
}

bool Time::operator>(Time const& other) const {
    return compare(other) > 0;
}

bool Time::operator<(Time const& other) const {
    return compare(other) < 0;
}

void Time::DisplayTime()
{
    if (hrs < 10 && mins < 10 && secs < 10)
        cout << "0" + to_string(hrs) << ":" << "0" + to_string(mins) << ":" << "0" + to_string(secs) << endl;
    else if (hrs < 10 && mins < 10)
        cout << "0" + to_string(hrs) << ":" << "0" + to_string(mins) << ":" << to_string(secs) << endl;
    else if (hrs < 10 && secs < 10)
        cout << "0" + to_string(hrs) << ":" << to_string(mins) << ":" << "0" + to_string(secs) << endl;
    else if (mins < 10 && secs < 10)
        cout << to_string(hrs) << ":" << "0" + to_string(mins) << ":" << "0" + to_string(secs) << endl;
    else if (hrs < 10)
        cout << "0" + to_string(hrs) << ":" << to_string(mins) << ":" << to_string(secs) << endl;
    else if (mins < 10)
        cout << to_string(hrs) << ":" << "0" + to_string(mins) << ":" << to_string(secs) << endl;
    else if (secs < 10)
        cout << to_string(hrs) << ":" << to_string(mins) << ":" << "0" + to_string(secs) << endl;
    else
        cout << to_string(hrs) << ":" << to_string(mins) << ":" << to_string(secs) << endl;
}

int main() {
    Time t1;
    t1.DisplayTime();
    t1.SetTime(12, 34, 59);
    t1.DisplayTime();
    t1--;
    t1.DisplayTime();
    return 0;
}




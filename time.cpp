#include <iostream>
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
        void Increment();
        void DisplayTime();
};

Time::Time()
{
    hrs = 0;
    mins = 0;
    secs = 0;
}

Time::Time(int h, int m, int s)
{
    this->hrs = h;
    this->mins = m;
    this->secs = s;
}

void Time::SetTime(int h, int m, int s)
{
    hrs = h;
    mins = m;
    secs = s;
}

void Time::Increment()
{
    secs++;
    if (secs >= 60)
    {
        secs = 0;
        mins++;
        if (mins >= 60)
        {
            mins = 0;
            hrs++;
            if (hrs >= 24)
            {
                hrs = 0;
            }
        }
    }
}

void Time::DisplayTime()
{
    cout << hrs << ":" << mins << ":" << secs << endl;
}

int main() {
    Time t1;
    t1.DisplayTime();
    t1.SetTime(23, 59, 59);
    t1.DisplayTime();
    t1.Increment();
    t1.DisplayTime();
    return 0;
}


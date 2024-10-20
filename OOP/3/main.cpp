#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <sstream>

class TimeOfDay {
private:
    int hours;
    int minutes;
    int seconds;

    void normalizeTime() {
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        }
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        }
        if (hours >= 24) {
            hours %= 24;
        }
    }

    int totalSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }

public:
    TimeOfDay(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {
        if (h < 0 || h >= 24 || m < 0 || m >= 60 || s < 0 || s >= 60) {
            throw std::invalid_argument("Invalid time");
        }
    }

    static TimeOfDay fromTotalSeconds(int totalSec) {
        if (totalSec < 0 || totalSec >= 86400) {
            throw std::invalid_argument("Invalid time in seconds");
        }
        int h = totalSec / 3600;
        int m = (totalSec % 3600) / 60;
        int s = totalSec % 60;
        return TimeOfDay(h, m, s);
    }

    int getHours() const {
        return hours;
    }

    int getMinutes() const {
        return minutes;
    }

    int getSeconds() const {
        return seconds;
    }

    int getTotalSeconds() const {
        return totalSeconds();
    }

    std::string toString() const {
        std::ostringstream oss;
        oss << std::setw(2) << std::setfill('0') << hours << ":"
            << std::setw(2) << std::setfill('0') << minutes << ":"
            << std::setw(2) << std::setfill('0') << seconds;
        return oss.str();
    }

    TimeOfDay operator+(const TimeOfDay& other) const {
        return TimeOfDay::fromTotalSeconds((totalSeconds() + other.totalSeconds()) % 86400);
    }

    TimeOfDay operator+(int sec) const {
        return TimeOfDay::fromTotalSeconds((totalSeconds() + sec) % 86400);
    }

    TimeOfDay& operator+=(const TimeOfDay& other) {
        *this = *this + other;
        return *this;
    }

    TimeOfDay& operator+=(int sec) {
        *this = *this + sec;
        return *this;
    }

    TimeOfDay operator-(const TimeOfDay& other) const {
        int diff = totalSeconds() - other.totalSeconds();
        return TimeOfDay::fromTotalSeconds((diff + 86400) % 86400);
    }

    TimeOfDay operator-(int sec) const {
        int diff = totalSeconds() - sec;
        return TimeOfDay::fromTotalSeconds((diff + 86400) % 86400);
    }

    TimeOfDay& operator-=(const TimeOfDay& other) {
        *this = *this - other;
        return *this;
    }

    TimeOfDay& operator-=(int sec) {
        *this = *this - sec;
        return *this;
    }

    TimeOfDay& operator++() {
        *this += 1;
        return *this;
    }

    TimeOfDay operator++(int) {
        TimeOfDay temp = *this;
        ++(*this);
        return temp;
    }

    TimeOfDay& operator--() {
        *this -= 1;
        return *this;
    }

    TimeOfDay operator--(int) {
        TimeOfDay temp = *this;
        --(*this);
        return temp;
    }

    bool operator==(const TimeOfDay& other) const {
        return totalSeconds() == other.totalSeconds();
    }

    bool operator<(const TimeOfDay& other) const {
        return totalSeconds() < other.totalSeconds();
    }
};

int main() {
    TimeOfDay t1(10, 45, 20);
    TimeOfDay t2(0, 30, 50);
    TimeOfDay t3 = TimeOfDay::fromTotalSeconds(7815); 

    TimeOfDay t4 = t1 + t2;
    TimeOfDay t5 = t1 - t2;

    t1 += 3600;
    t2 -= 40;

    ++t1;
    t2--;

    std::cout << t1.toString() << std::endl;
    std::cout << t2.toString() << std::endl;
    std::cout << t3.toString() << std::endl;
    std::cout << t4.toString() << std::endl;
    std::cout << t5.toString() << std::endl;

    return 0;
}

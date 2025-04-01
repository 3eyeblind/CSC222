#ifndef DATE_H
#define DATE_H

#include <string>

class Date
{
private:
    int month;
    int day;
    int year;
    bool validateDate(int m, int d, int y);

public:
    Date(int m = 1, int d = 1, int y = 1900);

    void setDate(int m, int d, int y);

    int getMonth() const { return month; }
    int getDay() const { return day; }
    int getYear() const { return year; }

    bool isLeapYear() const;
    bool isLeapYear(int year) const;

    int lastDay() const;
    int lastDay(int month, int year) const;

    std::string printNumeric() const;
    std::string printLong() const;
    std::string printLongReversed() const;
};

#endif
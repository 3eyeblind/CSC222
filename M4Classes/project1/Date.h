#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

class Date
{
private:
    int day, month, year;
    static const std::string monthNames[13];
    static int daysInMonth(int month, int year);
    static bool isLeapYear(int year);

public:
    Date(); // default
    Date(int m, int d, int y);
    bool setDate(int m, int d, int y);
    void printNumeric() const;
    void printText() const;

    // Overloaded operators
    Date operator++();    // prefix
    Date operator++(int); // postfix
    Date operator--();    // prefix
    Date operator--(int); // postfix
    int operator-(const Date &other) const;

    friend std::ostream &operator<<(std::ostream &out, const Date &date);
    friend std::istream &operator>>(std::istream &in, Date &date);
};

#endif
#include "Date.h"
#include <iostream>
#include <iomanip>
#include <cmath>

const std::string Date::monthNames[13] = {
    "", "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"};

bool Date::isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int Date::daysInMonth(int month, int year)
{
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year))
        return 29;
    return days[month];
}

Date::Date() : month(1), day(1), year(2000) {}

Date::Date(int m, int d, int y)
{
    if (!setDate(m, d, y))
        month = day = 1, year = 2000;
}

bool Date::setDate(int m, int d, int y)
{
    if (m < 1 || m > 12 || d < 1 || d > daysInMonth(m, y))
        return false;
    month = m;
    day = d;
    year = y;
    return true;
}

void Date::printNumeric() const
{
    std::cout << month << "/" << day << "/" << year << "\n";
}

void Date::printText() const
{
    std::cout << monthNames[month] << " " << day << ", " << year << "\n";
}

Date Date::operator++()
{
    if (++day > daysInMonth(month, year))
    {
        day = 1;
        if (++month > 12)
        {
            month = 1;
            ++year;
        }
    }
    return *this;
}

Date Date::operator++(int)
{
    Date temp = *this;
    ++(*this);
    return temp;
}

Date Date::operator--()
{
    if (--day < 1)
    {
        if (--month < 1)
        {
            month = 12;
            --year;
        }
        day = daysInMonth(month, year);
    }
    return *this;
}

Date Date::operator--(int)
{
    Date temp = *this;
    --(*this);
    return temp;
}

int Date::operator-(const Date &other) const
{
    struct std::tm a = {0, 0, 0, day, month - 1, year - 1900};
    struct std::tm b = {0, 0, 0, other.day, other.month - 1, other.year - 1900};
    std::time_t ta = std::mktime(&a);
    std::time_t tb = std::mktime(&b);
    return std::abs((int)std::difftime(ta, tb) / 86400);
}

std::ostream &operator<<(std::ostream &out, const Date &date)
{
    out << Date::monthNames[date.month] << " " << date.day << ", " << date.year;
    return out;
}

std::istream &operator>>(std::istream &in, Date &date)
{
    int m, d, y;
    char slash;
    std::cout << "Enter date (mm/dd/yyyy): ";
    in >> m >> slash >> d >> slash >> y;
    if (!date.setDate(m, d, y))
        std::cerr << "Invalid date.\n";
    return in;
}
#include "Date.h"
#include <iostream>
#include <sstream>
#include <vector>

Date::Date(int m, int d, int y)
{
    setDate(m, d, y);
}

void Date::setDate(int m, int d, int y)
{
    if (validateDate(m, d, y))
    {
        month = m;
        day = d;
        year = y;
    }
    else
    {
        std::cout << "Invalid date. Setting to default 1/1/1900.\n";
        month = 1;
        day = 1;
        year = 1900;
    }
}

bool Date::validateDate(int m, int d, int y)
{
    if (m < 1 || m > 12)
        return false;
    if (d < 1 || d > lastDay(m, y))
        return false;
    if (y < 1)
        return false;
    return true;
}

bool Date::isLeapYear() const
{
    return isLeapYear(year);
}

bool Date::isLeapYear(int y) const
{
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int Date::lastDay() const
{
    return lastDay(month, year);
}

int Date::lastDay(int m, int y) const
{
    switch (m)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return isLeapYear(y) ? 29 : 28;
    default:
        return 31;
    }
}

std::string Date::printNumeric() const
{
    std::ostringstream oss;
    oss << month << "/" << day << "/" << year;
    return oss.str();
}

std::string Date::printLong() const
{
    std::vector<std::string> monthNames = {
        "", "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};
    std::ostringstream oss;
    oss << monthNames[month] << " " << day << ", " << year;
    return oss.str();
}

std::string Date::printLongReversed() const
{
    std::vector<std::string> monthNames = {
        "", "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};
    std::ostringstream oss;
    oss << day << " " << monthNames[month] << " " << year;
    return oss.str();
}
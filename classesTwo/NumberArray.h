#ifndef NUMBERARRAY_H
#define NUMBERARRAY_H

#include <iostream>
using namespace std;

class NumberArray
{
private:
    static const int MAX_SIZE = 10;
    static constexpr double DEFAULT_VALUE = 10000.0;
    double *numbers;
    int size;

public:
    NumberArray(int s = MAX_SIZE);
    ~NumberArray();

    void setNumber(int index, double value);
    double getNumber(int index) const;
    double getHighest() const;
    double getLowest() const;
    double getAverage() const;
    void print() const;
};

#endif
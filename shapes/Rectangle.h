#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "BasicShape.h"

class Rectangle : public BasicShape
{
private:
    double length, width;

public:
    Rectangle(double l, double w, const std::string &n = "Rectangle")
        : length(l), width(w)
    {
        setName(n);
        calcArea();
    }

    double getLength() const { return length; }
    double getWidth() const { return width; }

    void calcArea() override
    {
        setArea(length * width);
    }
};

#endif
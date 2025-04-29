#ifndef CIRCLE_H
#define CIRCLE_H

#include "BasicShape.h"
#include <cmath>

class Circle : public BasicShape
{
private:
    double xCenter, yCenter, radius;

public:
    Circle(double x, double y, double r, const std::string &n = "Circle")
        : xCenter(x), yCenter(y), radius(r)
    {
        setName(n);
        calcArea();
    }

    double getXCenter() const { return xCenter; }
    double getYCenter() const { return yCenter; }
    double getRadius() const { return radius; }

    void calcArea() override
    {
        setArea(M_PI * radius * radius);
    }
};

#endif
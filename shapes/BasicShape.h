#ifndef BASICSHAPE_H
#define BASICSHAPE_H

#include <string>

class BasicShape
{
private:
    double area;
    std::string name;

public:
    virtual ~BasicShape() {}

    double getArea() const { return area; }
    std::string getName() const { return name; }

    void setArea(double a) { area = a; }
    void setName(const std::string &n) { name = n; }

    virtual void calcArea() = 0; // pure virtual
};

#endif
#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"

int main()
{
    BasicShape *shapes[5];

    shapes[0] = new Rectangle(5.0, 10.0, "Rectangle1");
    shapes[1] = new Rectangle(3.5, 6.0, "Rectangle2");
    shapes[2] = new Circle(0.0, 0.0, 4.0, "Circle1");
    shapes[3] = new Circle(2.0, 2.0, 7.5, "Circle2");
    shapes[4] = new Square(8.0, "Square1");

    for (int i = 0; i < 5; ++i)
    {
        std::cout << shapes[i]->getName() << " - Area: "
                  << shapes[i]->getArea() << std::endl;
        delete shapes[i];
    }

    return 0;
}
#include <iostream>
#include "Date.h"

int main()
{
    std::cout << "Test default constructor:\n";
    Date d1;
    std::cout << d1.printNumeric() << "\n\n";

    std::cout << "Test constructor with valid date:\n";
    Date d2(2, 28, 2009);
    std::cout << d2.printNumeric() << "\n\n";

    std::cout << "Test constructor with invalid month:\n";
    Date d3(45, 2, 2009);
    std::cout << d3.printNumeric() << "\n\n";

    std::cout << "Test constructor with invalid day:\n";
    Date d4(2, 29, 2009);
    std::cout << d4.printNumeric() << "\n\n";

    std::cout << "Test setDate with bad month:\n";
    d1.setDate(13, 1, 2009);
    std::cout << d1.printNumeric() << "\n\n";

    std::cout << "Test setDate with bad day:\n";
    d1.setDate(4, 31, 2009);
    std::cout << d1.printNumeric() << "\n\n";

    std::cout << "Test for leap year with bad date (2/29/2009):\n";
    d1.setDate(2, 29, 2009);
    std::cout << d1.printNumeric() << "\n\n";

    std::cout << "Test for leap year with good date (2/29/2008):\n";
    d1.setDate(2, 29, 2008);
    std::cout << d1.printNumeric() << "\n\n";

    std::cout << "Test the print formats:\n";
    std::cout << d1.printLong() << "\n";
    std::cout << d1.printLongReversed() << "\n";

    return 0;
}
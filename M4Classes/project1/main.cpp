#include "Date.h"

int main()
{
    Date d1, d2(4, 18, 2014);
    std::cout << "Default date: " << d1 << "\n";
    std::cout << "Parameterized date: " << d2 << "\n";

    d1.setDate(4, 10, 2014);
    std::cout << "Days between d1 and d2: " << (d2 - d1) << "\n";

    Date d3(2, 29, 2008);
    std::cout << "Original: " << d3 << "\n";
    std::cout << "Pre-decrement: " << --d3 << "\n";
    std::cout << "Post-increment: " << d3++ << "\n";
    std::cout << "After Post-increment: " << d3 << "\n";

    std::cin >> d1;
    std::cout << "You entered: " << d1 << "\n";

    return 0;
}
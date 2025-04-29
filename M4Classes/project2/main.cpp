#include <iostream>
#include "PoliceOfficer.h"

int main()
{
    // Scenario 1: No violation
    ParkedCar car1("Toyota", "Camry", "Red", "XYZ123", 30);
    ParkingMeter meter1(40);
    PoliceOfficer officer1("John Doe", "5678");
    ParkingTicket *ticket1 = officer1.inspect(car1, meter1);
    if (ticket1)
    {
        ticket1->printTicket();
        delete ticket1;
    }
    else
    {
        std::cout << "No ticket issued.\n";
    }

    // Scenario 2: Violation < 1 hour
    ParkedCar car2("Honda", "Accord", "Blue", "ABC987", 70);
    ParkingMeter meter2(60);
    PoliceOfficer officer2("Jane Smith", "1234");
    ParkingTicket *ticket2 = officer2.inspect(car2, meter2);
    if (ticket2)
    {
        ticket2->printTicket();
        delete ticket2;
    }

    // Scenario 3: Violation > 2 hours
    ParkedCar car3("Ford", "Mustang", "Black", "LMN456", 190);
    ParkingMeter meter3(60);
    PoliceOfficer officer3("James Brown", "4321");
    ParkingTicket *ticket3 = officer3.inspect(car3, meter3);
    if (ticket3)
    {
        ticket3->printTicket();
        delete ticket3;
    }

    return 0;
}
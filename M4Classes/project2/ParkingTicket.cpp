#include "ParkingTicket.h"
#include <iostream>
#include <cmath>

ParkingTicket::ParkingTicket(ParkedCar c, std::string name, std::string badge, int over)
    : car(c), officerName(name), officerBadge(badge), minutesOver(over)
{
    fine = 25.0;
    if (minutesOver > 60)
    {
        fine += 10.0 * ((minutesOver - 1) / 60);
    }
}

void ParkingTicket::printTicket() const
{
    std::cout << "\n*** Parking Ticket ***\n";
    std::cout << "Officer " << officerName << " Badge Number " << officerBadge << "\n";
    std::cout << "Vehicle License Number: " << car.getLicense() << "\n";
    std::cout << "Make: " << car.getMake() << " Model: " << car.getModel()
              << " Color: " << car.getColor() << "\n";
    std::cout << "Minutes Over: " << minutesOver << "\n";
    std::cout << "Fine: $" << fine << "\n";
}
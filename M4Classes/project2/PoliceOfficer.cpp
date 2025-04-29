#include "PoliceOfficer.h"

PoliceOfficer::PoliceOfficer(std::string n, std::string b) : name(n), badgeNumber(b) {}

ParkingTicket *PoliceOfficer::inspect(const ParkedCar &car, const ParkingMeter &meter) const
{
    int over = car.getMinutesParked() - meter.getMinutesPurchased();
    if (over > 0)
        return new ParkingTicket(car, name, badgeNumber, over);
    else
        return nullptr;
}
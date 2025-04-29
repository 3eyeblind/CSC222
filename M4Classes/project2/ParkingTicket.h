#ifndef PARKINGTICKET_H
#define PARKINGTICKET_H

#include <string>
#include "ParkedCar.h"
#include "PoliceOfficer.h"

class ParkingTicket
{
private:
    ParkedCar car;
    std::string officerName;
    std::string officerBadge;
    int minutesOver;
    double fine;

public:
    ParkingTicket(ParkedCar c, std::string name, std::string badge, int over);
    void printTicket() const;
};

#endif
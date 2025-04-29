#include "ParkingMeter.h"

ParkingMeter::ParkingMeter(int mins) : minutesPurchased(mins) {}

int ParkingMeter::getMinutesPurchased() const
{
    return minutesPurchased;
}
#ifndef PARKEDCAR_H
#define PARKEDCAR_H

#include <string>

class ParkedCar
{
private:
    std::string make, model, color, license;
    int minutesParked;

public:
    ParkedCar(std::string mk, std::string mdl, std::string clr, std::string lic, int mins);
    int getMinutesParked() const;
    std::string getMake() const;
    std::string getModel() const;
    std::string getColor() const;
    std::string getLicense() const;
};

#endif
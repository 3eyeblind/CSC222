#include "ParkedCar.h"

ParkedCar::ParkedCar(std::string mk, std::string mdl, std::string clr, std::string lic, int mins)
    : make(mk), model(mdl), color(clr), license(lic), minutesParked(mins) {}

int ParkedCar::getMinutesParked() const { return minutesParked; }
std::string ParkedCar::getMake() const { return make; }
std::string ParkedCar::getModel() const { return model; }
std::string ParkedCar::getColor() const { return color; }
std::string ParkedCar::getLicense() const { return license; }
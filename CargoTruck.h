#ifndef UNTITLED7_CARGOTRUCK_H
#define UNTITLED7_CARGOTRUCK_H
#include <iostream>
#include "Packages.h"
//
using namespace std;
class CargoTruck : public Packages{
    double power{};
public:
    //getter setter
    double getPower() const;

    void setPower(double power);
};

#endif //UNTITLED7_CARGOTRUCK_H

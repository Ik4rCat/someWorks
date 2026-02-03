#include <iostream>
#include <string>

#include "Vehicle.h"

using namespace std;

Vehicle vehicle;

int main()
{    
    vehicle.NewCar("Toyota sprinter turneo AE86", "Toyota", "white", 1997, 4, 1034);
    vehicle.GetAndPrintCarInfo();
}
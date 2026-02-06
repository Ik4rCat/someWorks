#include <iostream>
#include "Vehicle.h"

int main()
{
    Car car;

    car.SetInfo("Toyota", 1998, "95 ECTO", 45, 4.5);
    car.GetInfo();
}
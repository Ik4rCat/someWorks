#pragma once

#include <string>
using namespace std;

class Vehicle
{
    public:
        void GetAndPrintCarInfo();

        // ~ Name ~
        string GetName();
        void SetName(string newName);

        // ~ Brand ~
        string GetBrand();
        void SetBrand(string newBrand);

        // ~ Color ~
        string GetColor();
        void SetColor(string newColor);

        // ~ Year of manufacture ~
        int GetYearOfManufacture();
        void SetYearOfManufacture(int newYearOfManufacture);

        // ~ seats ~
        int GetSeat();
        void SetSeat(int newSeats);

        // ~ Horse Power ~
        int GetHorsePower();
        void SetHorsePower(int newHorsePower);

        void NewCar(string newName, string newBrand, string newColor, int newYearOfManufacture, int newSeats, int newHorsePower);
};
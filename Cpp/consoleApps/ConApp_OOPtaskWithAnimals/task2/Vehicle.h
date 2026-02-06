#pragma once
#include "Engine.h"

class Car
{
    private:
        Engine engine;

        std::string brand;
        int yearOfRelease;
    public:
        void GetInfo(){
            std::cout << "Car Info:" << std::endl;
            std::cout << "brand: " << brand << std::endl;
            std::cout << "year of release: " << yearOfRelease << std::endl;
            
            std::cout << "fuel type: " << engine.GetFuelType()  << std::endl;
            std::cout << "horse force: " << engine.GetHroseForse() << std::endl;
            std::cout << "volume: " << engine.GetVolume() << std::endl;
        }

        void SetInfo(std::string newBrand, int newYearOfRelease, std::string newEngineFuelType, 
            int newEngineHorseForse, double newEngineVolume){
                brand = newBrand;
                yearOfRelease = newYearOfRelease;
                engine.SetFullInfo(newEngineFuelType, newEngineHorseForse, newEngineVolume); 
            }
    
};
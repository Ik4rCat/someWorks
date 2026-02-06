#pragma once

class Engine{
    private:
        std::string fuelType;
        int horseForse;
        double volume;
    public:
        void SetFullInfo(std::string newFuelType, int newHorseForse, double newVolume){
            fuelType = newFuelType;
            horseForse = newHorseForse;
            volume = newVolume;
        }
        
        std::string GetFuelType(){
            return fuelType;
        }

        int GetHroseForse(){
            return horseForse;
        }

        double GetVolume(){
            return volume;
        }
};
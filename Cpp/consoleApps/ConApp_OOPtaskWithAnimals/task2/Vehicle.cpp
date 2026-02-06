#include <iostream>
#include "Engine.h"

Engine engine;

std::string brand; 
int yearOfRelease;

void GetInfo();
void SetInfo(std::string newBrand, int newYearOfRelease, std::string newEngineFuelType, int newEngineHorseForse, double newEngineVolume);
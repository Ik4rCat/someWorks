#include <iostream>
#include <string>
#include <vector>
#include <ctime>


using namespace std;

int actualYear = localtime(new time_t(time(nullptr)))->tm_year + 1900;
vector<int> carsData;


struct Car{
    string name;
    string color;
    string brand;
        
    int yearsOfTheCar;
    int yearOfManufacture;
    int seats;
    int horsePower;  
    int mileage;

    double coefficient;
};

Car car;

void GetAndPrintCarInfo(){

    car.yearsOfTheCar = actualYear- car.yearOfManufacture;

    cout << endl;
    cout << "car info" << endl;

    cout << "name: " << car.name << endl;
    cout << "brand: " << car.brand << endl;
    cout << "color: " << car.color << endl;
                
    cout << "years of the car: " << car.yearsOfTheCar <<endl;
    cout << "year of manufacture: " << car.yearOfManufacture << endl;
    cout << "seats: " << car.seats << endl;
    cout << "horse power: " << car.horsePower << endl;
    cout << "mileage: " << car.mileage << endl;

    cout << "car coefficient: " << car.mileage/car.yearsOfTheCar << endl;
    }

// ~ get & set funcs ~

// ~ name ~
string GetName(){
    return car.name;
}

void SetName(string newName){
    car.name = newName;
}

// ~ Brand ~
string GetBrand(){
    return car.brand;
}

void SetBrand(string newBrand){
    car.brand = newBrand;
}

// ~ Color ~
string GetColor(){
    return car.color;
}

void SetColor(string newColor){
    car.color = newColor;
}

// ~ Year of manufacture ~
int GetYearOfManufacture(){
    return car.yearOfManufacture;
}

void SetYearOfManufacture(int newYearOfManufacture){
    car.yearOfManufacture = newYearOfManufacture;
}

// ~ seats ~
int GetSeat(){
    return car.seats;
}

void SetSeat(int newSeats){
    car.seats = newSeats;
}

// ~ Horse Power ~
int GetHorsePower(){
    return car.horsePower;
}

void SetHorsePower(int newHorsePower){
    car.horsePower = newHorsePower;
}


void NewCar(string newName, string newBrand, string newColor, int newYearOfManufacture, int newSeats, int newHorsePower){
    car = {newName, newBrand, newColor, newYearOfManufacture, newSeats, newHorsePower};
}


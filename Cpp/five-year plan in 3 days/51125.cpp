#include <iostream>
#include <cmath>
using namespace std;

const double kPi = 3.1415926535;

void calcHollowCylinderVolume() {
    double rOuter, rInner, height;
    cout << "Enter outer radius, inner radius, and height: ";
    cin >> rOuter >> rInner >> height;

    const double volume = kPi * height * (pow(rOuter, 2) - pow(rInner, 2));
    cout << "Hollow cylinder volume: " << volume << "\n";
}

void calcConeVolume() {
    double radius, height;
    cout << "Enter cone radius and height: ";
    cin >> radius >> height;

    const double volume = (1.0 / 3.0) * kPi * pow(radius, 2) * height;
    cout << "Cone volume: " << volume << "\n";
}

void calcCylinderVolume() {
    double radius, height;
    cout << "Enter cylinder radius and height: ";
    cin >> radius >> height;

    const double volume = kPi * pow(radius, 2) * height;
    cout << "Cylinder volume: " << volume << "\n";
}

void calcCurrentFromVoltageAndResistance() {
    double voltage, resistance;
    cout << "Enter voltage (U) and resistance (R): ";
    cin >> voltage >> resistance;

    // Ohm's law: I = U / R
    const double current = voltage / resistance;
    cout << "Current: " << current << " A\n";
}

void calcResistanceFromVoltageAndCurrent() {
    double voltage, current;
    cout << "Enter voltage (U) and current (I): ";
    cin >> voltage >> current;

    const double resistance = voltage / current;
    cout << "Resistance: " << resistance << " Ohm\n";
}

void calcSeriesResistance() {
    double r1, r2, r3;
    cout << "Enter three series resistances: ";
    cin >> r1 >> r2 >> r3;

    cout << "Total series resistance: " << (r1 + r2 + r3) << " Ohm\n";
}

int main() {
    while (true) {
        cout << "\n=== Geometry and Circuits ===\n";
        cout << "1. Hollow cylinder volume\n";
        cout << "2. Cone volume\n";
        cout << "3. Cylinder volume\n";
        cout << "4. Current from voltage and resistance\n";
        cout << "5. Resistance from voltage and current\n";
        cout << "6. Series resistance\n";
        cout << "0. Exit\n";
        cout << "Select: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: calcHollowCylinderVolume(); break;
        case 2: calcConeVolume(); break;
        case 3: calcCylinderVolume(); break;
        case 4: calcCurrentFromVoltageAndResistance(); break;
        case 5: calcResistanceFromVoltageAndCurrent(); break;
        case 6: calcSeriesResistance(); break;
        case 0: return 0;
        default: cout << "Unknown option.\n"; break;
        }
    }
}


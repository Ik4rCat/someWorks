#include <iostream>
#include <cmath>
using namespace std;

void task1() {
    int totalSeconds;
    cout << "Enter duration in seconds: ";
    cin >> totalSeconds;

    // Break total seconds into hour/minute/second buckets.
    const int hours = totalSeconds / 3600;
    const int minutes = (totalSeconds % 3600) / 60;
    const int seconds = totalSeconds % 60;

    cout << "Hours: " << hours << "\n";
    cout << "Minutes: " << minutes << "\n";
    cout << "Seconds: " << seconds << "\n";
}

void task2() {
    double amount;
    cout << "Enter amount in dollars: ";
    cin >> amount;

    const int dollars = static_cast<int>(amount);
    const int cents = static_cast<int>(round((amount - dollars) * 100));

    cout << dollars << " dollars and " << cents << " cents\n";
}

void task3() {
    int totalDays;
    cout << "Enter number of days: ";
    cin >> totalDays;

    const int weeks = totalDays / 7;
    const int days = totalDays % 7;

    cout << "Weeks: " << weeks << "\n";
    cout << "Days: " << days << "\n";
}

void task4() {
    double distanceMeters;
    double timeInMinutesSeconds;
    cout << "Calculating running speed.\n";
    cout << "Enter distance in meters: ";
    cin >> distanceMeters;
    cout << "Enter time (format minutes.seconds): ";
    cin >> timeInMinutesSeconds;

    const int minutes = static_cast<int>(timeInMinutesSeconds);
    const int seconds = static_cast<int>(round((timeInMinutesSeconds - minutes) * 100));

    // Convert the user-friendly format mm.ss to a pure second count.
    const double totalSeconds = minutes * 60 + seconds;
    const double speedMetersPerSecond = distanceMeters / totalSeconds;
    const double speedKmPerHour = speedMetersPerSecond * 3.6;

    cout << "Distance: " << distanceMeters << " m\n";
    cout << "Time: " << minutes << " min " << seconds << " sec = " << totalSeconds << " seconds\n";
    cout << "Speed: " << speedKmPerHour << " km/h\n";
}

void task5() {
    double deposit;
    double annualPercent;
    cout << "Enter deposit amount in EUR: ";
    cin >> deposit;
    cout << "Enter annual percent: ";
    cin >> annualPercent;

    const double monthlyIncome = deposit * annualPercent / 100.0 / 12.0;
    cout << "Monthly income: " << monthlyIncome << " EUR\n";
}

void task6() {
    float distanceKm;
    int timeMinutes;
    cout << "Distance to the airport (km): ";
    cin >> distanceKm;
    cout << "Time to get there (minutes): ";
    cin >> timeMinutes;

    const float speed = distanceKm / timeMinutes;
    cout << "Required speed: " << speed << " km/min\n";
}

void task7() {
    int h1, m1, s1;
    int h2, m2, s2;
    const int pricePerMinute = 2;

    cout << "Start time (h m s): ";
    cin >> h1 >> m1 >> s1;
    cout << "End time (h m s): ";
    cin >> h2 >> m2 >> s2;

    const float startMinutes = h1 * 60 + m1 + s1 / 60.0f;
    const float endMinutes = h2 * 60 + m2 + s2 / 60.0f;
    const float durationMinutes = endMinutes - startMinutes;
    const float totalCost = durationMinutes * pricePerMinute;

    cout << "Trip cost: " << totalCost << " UAH\n";
}

void task8() {
    float distance, fuelConsumption;
    float priceSuper, priceSuperPlus, priceDiesel;

    cout << "Distance (km): ";
    cin >> distance;
    cout << "Fuel consumption per 100 km: ";
    cin >> fuelConsumption;
    cout << "Price Super: ";
    cin >> priceSuper;
    cout << "Price Super Plus: ";
    cin >> priceSuperPlus;
    cout << "Price Diesel: ";
    cin >> priceDiesel;

    const float costSuper = distance * priceSuper * fuelConsumption / 100.0f;
    const float costSuperPlus = distance * priceSuperPlus * fuelConsumption / 100.0f;
    const float costDiesel = distance * priceDiesel * fuelConsumption / 100.0f;

    cout << "|Fuel type|Trip cost|\n";
    cout << "Super\t\t" << costSuper << "\n";
    cout << "Super Plus\t" << costSuperPlus << "\n";
    cout << "Diesel\t\t" << costDiesel << "\n";
}

void task9() {
    int userNumber;
    cout << "Enter a 6-digit number: ";
    cin >> userNumber;

    if (userNumber < 100000 || userNumber > 999999) {
        cout << "The number must have exactly 6 digits\n";
        return;
    }

    // Extract digits from right to left.
    int d6 = userNumber % 10; userNumber /= 10;
    int d5 = userNumber % 10; userNumber /= 10;
    int d4 = userNumber % 10; userNumber /= 10;
    int d3 = userNumber % 10; userNumber /= 10;
    int d2 = userNumber % 10; userNumber /= 10;
    int d1 = userNumber;

    const int sum1 = d1 + d2 + d3;
    const int sum2 = d4 + d5 + d6;

    cout << (sum1 == sum2 ? "Lucky number\n" : "Not a lucky number\n");
}

void task10() {
    int userNumber;
    cout << "Enter a 4-digit number: ";
    cin >> userNumber;

    if (userNumber < 1000 || userNumber > 9999) {
        cout << "The number must have exactly 4 digits\n";
        return;
    }

    int d4 = userNumber % 10; userNumber /= 10;
    int d3 = userNumber % 10; userNumber /= 10;
    int d2 = userNumber % 10; userNumber /= 10;
    int d1 = userNumber;

    const int newNumber = d2 * 1000 + d1 * 100 + d4 * 10 + d3;
    cout << "New number: " << newNumber << "\n";
}

void task11() {
    int numbers[7];
    cout << "Enter seven integers:\n";
    for (int i = 0; i < 7; ++i) {
        cin >> numbers[i];
    }

    // Linear scan to track the current maximum.
    int maxNumber = numbers[0];
    for (int i = 1; i < 7; ++i) {
        if (numbers[i] > maxNumber) {
            maxNumber = numbers[i];
        }
    }

    cout << "Maximum: " << maxNumber << "\n";
}

int main() {
    while (true) {
        cout << "\n=== Utility Tasks ===\n";
        cout << "1. Convert seconds to h:m:s\n";
        cout << "2. Split dollars and cents\n";
        cout << "3. Convert days to weeks and days\n";
        cout << "4. Running speed calculator\n";
        cout << "5. Monthly income from deposit\n";
        cout << "6. Required speed to airport\n";
        cout << "7. Taxi ride cost\n";
        cout << "8. Trip cost by fuel type\n";
        cout << "9. Lucky 6-digit number check\n";
        cout << "10. Swap digits in a 4-digit number\n";
        cout << "11. Find maximum of seven numbers\n";
        cout << "0. Exit\n";
        cout << "Select: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 4: task4(); break;
        case 5: task5(); break;
        case 6: task6(); break;
        case 7: task7(); break;
        case 8: task8(); break;
        case 9: task9(); break;
        case 10: task10(); break;
        case 11: task11(); break;
        case 0: return 0;
        default: cout << "Unknown option.\n"; break;
        }
    }

}

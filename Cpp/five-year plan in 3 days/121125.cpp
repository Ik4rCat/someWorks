#include <iostream>
#include <cmath>
using namespace std;

void task1() {
    const float pizzaPrices[4] = { 6.75f, 8.95f, 14.5f, 10.25f };
    const float drinkPrices[3] = { 1.79f, 2.5f, 3.09f };

    int pizzaID, drinkID, pizzaAmount, drinkAmount;
    cout << "Choose pizza (1-4): ";
    cin >> pizzaID;
    cout << "Pizza quantity: ";
    cin >> pizzaAmount;
    cout << "Choose drink (1-3): ";
    cin >> drinkID;
    cout << "Drink quantity: ";
    cin >> drinkAmount;

    float pizzaPrice = (pizzaID >= 1 && pizzaID <= 4) ? pizzaPrices[pizzaID - 1] : 0.0f;
    float drinkPrice = (drinkID >= 1 && drinkID <= 3) ? drinkPrices[drinkID - 1] : 0.0f;

    int paidPizzas = pizzaAmount;
    // Fifth pizza is free.
    if (pizzaAmount >= 5) {
        paidPizzas -= pizzaAmount / 5;
    }
    float total = paidPizzas * pizzaPrice;

    if (drinkPrice > 2.0f && drinkAmount >= 3) {
        total += drinkAmount * drinkPrice * 0.85f;
    } else {
        total += drinkAmount * drinkPrice;
    }

    if (total > 50.0f) {
        total *= 0.8f;
    }

    cout << "Order summary:\n";
    cout << "Pizza ID " << pizzaID << " | Qty: " << pizzaAmount << " | Unit: $" << pizzaPrice << "\n";
    cout << "Drink ID " << drinkID << " | Qty: " << drinkAmount << " | Unit: $" << drinkPrice << "\n";
    cout << "Total: $" << total << "\n";
}

void task2() {
    int sales[3];
    float salaries[3];

    for (int i = 0; i < 3; ++i) {
        cout << "Sales volume for manager " << i + 1 << ": ";
        cin >> sales[i];
        if (sales[i] < 500) salaries[i] = 200 + sales[i] * 0.03f;
        else if (sales[i] < 1000) salaries[i] = 200 + sales[i] * 0.05f;
        else salaries[i] = 200 + sales[i] * 0.08f;
    }

    int best = 0;
    if (sales[1] > sales[best]) best = 1;
    if (sales[2] > sales[best]) best = 2;
    salaries[best] += 200;

    cout << "Top manager: " << best + 1 << "\n";
    for (int i = 0; i < 3; ++i) {
        cout << "Salary " << i + 1 << ": $" << salaries[i] << "\n";
    }
}

void task3() {
    char ch;
    cout << "Enter a character: ";
    cin >> ch;
    int code = static_cast<int>(ch);

    if ((code >= 65 && code <= 90) || (code >= 97 && code <= 122)) {
        cout << "Letter\n";
    } else if (code >= 48 && code <= 57) {
        cout << "Digit\n";
    } else if (code == 33 || (code >= 44 && code <= 46) || code == 58 || code == 59 || code == 63) {
        cout << "Punctuation\n";
    } else {
        cout << "Other symbol\n";
    }
}

void task4() {
    const float rates[3] = { 2.0f, 3.0f, 2.5f };
    int operatorUser, operatorPeer, minutes;
    cout << "Select your operator (1-orange, 2-vodafone, 3-att): ";
    cin >> operatorUser;
    cout << "Select peer operator (1-3): ";
    cin >> operatorPeer;
    cout << "Call duration (minutes): ";
    cin >> minutes;

    if (operatorUser == operatorPeer) {
        cout << "Call is free.\n";
        return;
    }

    if (operatorUser >= 1 && operatorUser <= 3) {
        cout << "Call cost: $" << rates[operatorUser - 1] * minutes << "\n";
    } else {
        cout << "Unknown operator.\n";
    }
}

void task5() {
    const float pricePerLine = 0.5f;
    int mode;
    cout << "Coding productivity mode (1/2/3): ";
    cin >> mode;

    if (mode == 1) {
        int income, late;
        cout << "Desired income: ";
        cin >> income;
        cout << "Late arrivals: ";
        cin >> late;
        int lines = static_cast<int>(income / pricePerLine);
        if (late >= 3) {
            const int penalty = (late / 3) * 20;
            lines += static_cast<int>(penalty / pricePerLine);
        }
        cout << "You must write " << lines << " lines of code.\n";
    } else if (mode == 2) {
        int income, lines;
        cout << "Desired income: ";
        cin >> income;
        cout << "Lines already written: ";
        cin >> lines;
        float earned = lines * pricePerLine;
        if (earned < income) {
            cout << "No lateness allowed.\n";
        } else {
            float extra = earned - income;
            int maxPenalties = static_cast<int>(extra / 20);
            cout << "You can be late up to " << maxPenalties * 3 + 2 << " times.\n";
        }
    } else if (mode == 3) {
        int lines, late;
        cout << "Lines written: ";
        cin >> lines;
        cout << "Late arrivals: ";
        cin >> late;
        float earned = lines * pricePerLine;
        int penalty = (late >= 3) ? (late / 3) * 20 : 0;
        if (penalty >= earned) {
            cout << "Salary: $0 (penalties consumed everything)\n";
        } else {
            cout << "Salary: $" << earned - penalty << "\n";
        }
    } else {
        cout << "Unknown mode.\n";
    }
}

int main() {
    while (true) {
        cout << "\n=== Business Utilities ===\n";
        cout << "1. Pizza and drinks order\n";
        cout << "2. Manager salaries\n";
        cout << "3. Character classification\n";
        cout << "4. Call cost calculator\n";
        cout << "5. Coding productivity helper\n";
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
        case 0: return 0;
        default: cout << "Unknown option.\n"; break;
        }
    }
}

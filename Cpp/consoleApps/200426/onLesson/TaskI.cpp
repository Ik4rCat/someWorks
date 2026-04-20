#include <iostream>
using namespace std;

double ApplyDiscount(double price, double discount){
    double result = price - price * discount / 100;
    if (discount > 50){
        cout << "big discount!" << endl;
    }

    return result;
}

int main(){
    double price = 100;
    double discount = 60;
    double final = ApplyDiscount(price, discount);
    
    cout << "final price: " << final << endl;
    
    return 0;
}

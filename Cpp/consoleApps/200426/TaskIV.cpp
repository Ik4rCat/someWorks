#include <iostream> 
using namespace std;


double balance = 1000.0;

double WithDraw(double amount){
    if(amount <= balance){
        balance = balance - amount;
        return balance;
    }
    else 
    {
        cout << "little balance" << endl;
        return balance;
    }
}

int main(){
    cout << WithDraw(1200) << endl;
    cout << WithDraw(500) << endl;
    cout << WithDraw(300) << endl;
    cout << balance << endl;
    return 0;
}
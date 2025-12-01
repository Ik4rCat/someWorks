#include <iostream>
using namespace std;

void TaskI()
{
    int number;
    cout << "Enter number: ";
    cin >> number;
    if (number > 999){
        cout << "Error, wrong number";
    }
    else if (number / 100 == number % 100 / 10 || 
        number / 100 == number % 10 ||
        number % 100 / 10 == number % 10)
    {
        cout << "found";
    }
    else
    {
        cout << "not found";
    }
}


void TaskII()
{
    int i, sum, n=1;
    double d;
    
    cout << "Enter n value: ";
    cin >> n;
    
    double* p = new double[n];

    for (i = 0; i < n; i++){
        p[i] = rand() % 10 + (-5);
    }
    for (i = 0; i < n; i++){
        cout << p[i] << "\t";
    }
    for (i = 0; i < n; i++){
        if(abs(p[i]) > 2){
            sum = sum +(p[i]*p[i]);
        }
    }
    cout << sum;

}


int main()
{
    srand(time(0));

    while (true)
    {
        int choice;
        
        cout << "\nChoice task:" << endl;
        cout << "1 - taskI" << endl;
        cout << "2 - taskII" << endl;
        cout << "0 - exit" << endl;
        cin >> choice;

        switch(choice){
        case 1: TaskI(); break;
        case 2: TaskII(); break;
        case 0: return 0;
        default:
            cout << "\nerror value, try again" << endl; break;
        }
    }
    
}
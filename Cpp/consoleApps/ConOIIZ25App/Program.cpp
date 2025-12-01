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
    int n=1;
    double d;

    cout << "Enter n value: ";
    cin >> n;

    while(true){
        cin >> d;
        if(d == 0){
            break;
        }
        n++;
        double* v = new double[n];
        
        
        v[n-1]=d;

    }

}


int main()
{
    int choice;

    srand(time(0));

    while (true)
    {
        cout << "\nChoice task:" << endl;
        cout << "1 - taskI" << endl;
        cout << "2 - taskII" << endl;
        cout << "0 - exit" << endl;

        switch (choice)
        {
            case 1: TaskI; break;
            case 2: TaskII; break;
        default:
            cout << "error value, try again" << endl; break;
        }
    }
    
}
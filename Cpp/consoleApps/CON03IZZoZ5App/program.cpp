#include <iostream>
using namespace std;

class TaskI 
{
    void area(int r){
        double S = 3.14 * r * r;
        cout << "\nArea of circle: " << S << endl;
    }

    void area(int x, int y){
        int S = x * y;
        cout << "\nArea of rectangle: " << S << endl;
    }

    void area(int a, int b, int h){
        int S = a + b / 2 * h;
        cout << "\nArea of trapezoid: " << S << endl;
    }


    public: void Program() 
    {
        int choice;

        cout << "\nChoice figure: " << endl;
        cout << "1 - circle" << endl;
        cout << "2 - rectangle" << endl;
        cout << "3 - trapezoid" << endl;

        cin >> choice;

        switch (choice){
            case 1: {
                int r;
                cout << "\nEnter radius: ";
                cin >> r;
                area(r);
                break;
            }
            case 2: {
                int x, y;
                cout << "\nEnter width and height: ";
                cin >> x >> y;
                area(x, y);
                break;
            }
            case 3: {
                int a, b, h;
                cout << "\nEnter bases and height: ";
                cin >> a >> b >> h;
                area(a, b, h);
                break;
            }
            default:
                cout << "\nerror value, try again" << endl;
                break;
        }    

    }
        

};


class TaskII
{

    void sum(int x, int y){
        cout << "\nSum: " << x + y << endl;
    }

    void sum(int x, int y, int z){
        cout << "\nSum: " << x + y + z << endl;
    }

    void sum(double x, double y){
        cout << "\nSum: " << x + y << endl;
    }

    public: void Program() 
    {
        int choice;

        cout << "\nChoice sum: " << endl;
        cout << "1 - sum of two friendly" << endl;
        cout << "2 - sum of three friendly" << endl;
        cout << "3 - sum of two fractioned friendly" << endl;

        cin >> choice;

        switch (choice){
            case 1: {
                int x, y;
                cout << "\nEnter two friendly: ";
                cin >> x >> y;
                sum(x, y);
                break;
            }
            case 2: {
                int x, y, z;
                cout << "\nEnter three friendly: ";
                cin >> x >> y >> z;
                sum(x, y, z);
                break;
            }
            case 3: {
                double x, y;
                cout << "\nEnter two fractioned friendly: ";
                cin >> x >> y;
                sum(x, y);
                break;
            }
            default:
                cout << "\nerror value, try again" << endl;
                break;
        }    
    }
    
};


class TaskIII
{
    
    int sumDigits(int n){
        int sum = 0;
        if (n = 0){
            cout << "Bro, it's : " << n << "what u want summing here?" << endl;
            return n;
        }
    }

    public: void Program() 
        {
            int num;

            cout << "Enter friendly num: " << endl;
            cin >> num;

            sumDigits(num);

        }

};


int main()
{

    TaskI taskI;
    TaskII taskII;
    TaskIII taskIII;

    srand(time(0));

    while(true){

        int choice;

        cout << endl;
        cout << "Choice task: " << endl;
        cout << "1 - taskI" << endl;
        cout << "2 - taskII" << endl;
        cout << "3 - taskIII" << endl;
        cout << "0 - exit" << endl;

        cin >> choice;

        switch (choice){
        case 1: taskI.Program(); break;
        case 2: taskII.Program(); break;
        case 3: taskIII.Program(); break;
        case 0: cout << "Exiting program..." << endl; return 0;

        default:
            cout << "error value, try again" << endl;
            break;
        }
    }
}

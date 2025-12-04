#include <iostream>
#include <string>
using namespace std;

class TaskI
{

    int i, q, s=1;

    void Checker(int mass[], int x){
        for (i=0; i < s; i++){
            if(mass[i] == x){
                for (q = i; q < s; q++) {
                    mass[q] = mass[q + 1];
                }
                s--;
                i--;
            }
        }

        cout << "massive size: " << x << endl;

        for (i = 0; i < s; i++){
            cout << mass[i] << "\t";

        }

    } 


    public: void Program(){
        int usrNum;
        int massive[s]{};

        while (true)
        {
            cout << "Enter massive size: " << endl;
            cin >> s;
            if (s > 0) break;
            else cout << "bad value, try again" << endl;
        }
        

        for(i = 0; i < s; i++){
            cout << "Enter num for massive: "; 
            cin >> massive[i];
        }

        cout << "Your massive: " << endl;

        for(i = 0; i < s; i++){
            cout << massive[i] << "\t";
        }

        cout << "\nEnter num u wana delete: " << endl;
        cin >> usrNum;

        Checker(massive, usrNum);

    }
};

class TaskII
{
    int size = rand() % (15-3+1), i;

    void delDubbles(int mass[]){
        int bclone[size];

        for(i = 0; i < size; i++){
            bclone[i] = mass[i];
        }    

        //check_time
        for (i = 0; i < size; i++){

        }

    }

    public: void Program(){
        int massive[size];

        cout << "massive size: " << size << endl;

        for (i = 0; i < size; i++){
            massive[i] = rand() % 100;
        }

        cout << "your massive:"  << endl;

        for (i = 0; i < size; i++){
            cout << massive[i] << "\t";
        }
        cout << endl;

    }

};

int main()
{
    TaskI taskI;
    TaskII taskII;

    srand(time(0));

    while(true){

        int choice;

        cout << endl;
        cout << "Choice task: " << endl;
        cout << "1 - taskI" << endl;
        // cout << "2 - taskII" << endl;
        cout << "0 - exit" << endl;

        cin >> choice;

        switch (choice){
        case 1: taskI.Program(); break;
        // case 2: taskII.Program(); break;
        case 0: return 0;

        default:
            cout << "error value, try again" << endl;
            break;
        }

    }

}
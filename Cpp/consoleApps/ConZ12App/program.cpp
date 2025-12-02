#include <iostream>
#include <string>
using namespace std;

class TaskI
{

    private: static const int x = 1, y = 7;

    void ViewPlans(string week[], string mas[y][x]){
        
        int ch;

        for (int i = 0; i < 8; i++){
            cout << week[i] << " ";
        }
        cout << endl;

        cout << "Choice day: ";
        cin >> ch;

    }


    void AddPlans(){

    }

    void Menu(){

        cout << "Welcome, user!\n what's your plans today?" << endl;
        
        cout << " Watch part==>" << endl;
        cout << "  - 1. View weekly schedule" << endl;
        
        cout << " Settings part==>";
        cout << "  - 4. add plans" << endl;;

        cout << "0 - exit" << endl;

    }

    public: void Program(){
        
        int weekNums[]{1, 2, 3, 4, 5, 6, 7};
        
        string weekNames[]{"Monday", "Tuesday", "Wednesday", "Thursday",
                           "Friday", "Saturday", "Sunday"};
        string notes[y][x]{};
        

        while(true){
            int usrChoice;

            Menu();

            cin >> usrChoice;

            switch(true){
                case 1: ViewPlans(weekNames, notes); break;
                case 4: AddPlans(); break;

                case 0: return;

            }
        }

    }
};

class TaskII
{
    private: static const int x = 5, y = 5;

    void fillMas(int mas[x][y]) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                mas[i][j] = 30 + rand() % 31;
            }
        }
    }

    void printMas(int mas[x][y]) {
        cout << "massive 5x5:" << endl;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << mas[i][j] << "\t";
            }
            cout << endl;
        }
    }

    int findMax(int mas[x][y]) {
        int max = mas[0][0];
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (mas[i][j] > max) {
                    max = mas[i][j];
                }
            }
        }
        return max;
    }

    int findMin(int mas[x][y]) {
        int min = mas[0][0];
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (mas[i][j] < min) {
                    min = mas[i][j];
                }
            }
        }
        return min;
    }

    public: void MainClassScript()
    {
        int massive[x][y];

        fillMas(massive);
        printMas(massive);

        int maxElement = findMax(massive);
        cout << "\nmax value: " << maxElement << endl;
    
        int minElement = findMin(massive);
        cout << "min value: " << minElement << endl;


    }

};

int main()
{
    TaskI taskI;
    TaskII taskII;

    srand(time(0));

    while(true){

        int choice;

        cout << "Choice task: " << endl;
        cout << "1 - taskI" << endl;
        cout << "2 - taskII" << endl;
        cout << "0 - exit" << endl;

        cin >> choice;

        switch (choice){
        case 1: taskI.Program(); break;
        case 2: taskII.MainClassScript(); break;

        default:
            cout << "error value, try again" << endl;
            break;
        }

    }

}
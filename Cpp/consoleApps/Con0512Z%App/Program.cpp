#include <iostream>
#include <string>
#include <random>
using namespace std;

class GuessingGame {

    int exitCode, number, tryUHave, minValue = 1, maxValue = 10, i, q, j, n = 0;

    void MakeAWish(){
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(minValue, maxValue);

        number = distrib(gen);

        cout << "Random num wished: " << endl;
    }

    void HotOrCold(int usrN){
        
        string ch;

        if (number == usrN){
            while (true)
            {
                cout << "YEEEES U RIGHT, U WIIIIIN LEEEET'sSSS GOOOOOOOOO!!!" << endl;
                cout << "wana try again?" << endl;
                cout << "if yes press 'a', if not press e" << endl;
                cin >> ch;

                if (ch == "a") Started();
                else if (ch == "e") return;
                else cout << "error value, try again" << endl;
            }
        }
        else if (usrN < number){
            cout << "my number bigger"<< endl;
        }
        else if (usrN > number){
            cout << "my number smaller" << endl;
        }
        else cout << "idk what happend, try again i think"<< endl;
            
    }

    void Started(){

        tryUHave = 5;

        cout << "OKEY, now i wish a num, give a sec..."<< endl;

        MakeAWish();

        cout << "OKEY here we go, i wished num from " << minValue << " to " << maxValue << endl;
        cout << "u have " << tryUHave << " tryings";

        while (n < tryUHave)
        {
            int usrNum;
            cout << "bad tryings now - " << n << endl;
            cout << "So, your number?" << endl;
            cin >> usrNum;

            HotOrCold(usrNum);

        }
        

    }

    public: void Program(){
        string choice;

        cout << "WELCOME, WELCOME !USER!" << endl;
        cout << "NOW I WILL MAKE A WISH NUM" << endl;
        cout << "AND Uuuuuuuuuuu~" << endl;
        cout << "NEED TO GGUuueeEES it, ARE U READY???!" << endl;

        // cout << "PRESS ANY BUTTON TO START"<< endl;
        cout << "PRESS p BUTTON TO START" << endl;
        cout << "press e to exit"<< endl;
        cin >> choice;

        while (true)
        {
            if (choice == "p") Started();
            else if (choice == "e") return;
            else cout << "error value, try again" << endl;
        }
    }
        
};

class PassGen{

    public: void Program(){
        cout << "not done yet" << endl;
    }

};


int main() {
    
    // random_device rd;
    // mt19937 gen(rd());
    // uniform_int_distribution<> distrib(1, 100);
    // uniform_real_distribution<> dist(25.5, 103.4942);

    // for (int i = 0; i < 10; i++) {
    //     cout << "Random Integer: " << distrib(gen) << endl;
    //     cout << "Random Float: " << dist(gen) << endl;
    // }

    GuessingGame gsg;
    PassGen psg;

    int choice;

    while (true)
    {
        cout << endl;
        cout << "Choice program: " << endl;
        cout << " - Num guessing game (1)" << endl;
        cout << " - Password generation (2)" << endl;
        cout << " - exit [0]" << endl;

        cin >> choice;

        switch(choice){
            case 1: gsg.Program(); break; 
            case 2: psg.Program(); break;
            case 0: return 0;

            default: cout << "error value, try again" << endl; break;
        }
    }
    
    
}

#include <iostream>
using namespace std;

void TaskI() 
{
    int i;
    int* p = new int[1]; 
    int* u = nullptr;    

    cout << "Before allocation:\n";
    cout << "p: " << p << "\n" << "u: " << u << endl;

    for (i = 1; i <= 10; i++) {
        u = new int[i]; 
        delete[] p;     
        p = u;          
    }

    cout << "After allocation:\n";
    cout << "p: " << p << "\n" << "u: " << u << endl;

    for (int j = 0; j < 10; ++j) {
        p[j] = j + 1;
    }

    int sum = 0;
    int product = 1;

    for (int j = 0; j < 10; ++j) {
        sum += p[j];
        product *= p[j];
    }

    cout << "Summ: " << sum << endl;
    cout << "work: " << product << endl;

    delete[] p;
}

void TaskII() 
{

}

int main()
{
	srand(time(0));

	int usrInp;

	while (true) {
		cout << "\nChoice task:" << endl;
		cout << " task1 - 1" << endl;
		//cout << " task2 - 2" << endl;
		//cout << " task3 - 3" << endl;
		//cout << " task4 - 4" << endl;
		//cout << " task5 - 5" << endl;
		cout << " exit - 0" << endl;

		cin >> usrInp;
		cout << endl;

		switch (usrInp){
		case 1: TaskI(); break;
		//case 2: TaskII(); break;
		//case 3: TaskIII(); break;
		//case 4: TaskIV(); break;
		//case 5: TaskV(); break;
		case 0: return 0;
		default:
			cout << "\nWe dont have task like this, try again" << endl;
			break;
		}

	}
}

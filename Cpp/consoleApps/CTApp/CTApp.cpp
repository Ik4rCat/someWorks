#include <iostream>
#include <string>
#include <locale>
using namespace std;

/// HI, i need to make my taskes (。_。) 

void taskI()
{

	int userInp, result, max = 0;

	cout << "Enter num: " << endl;
	cin >> userInp;

	while (userInp > 0) {
		result = userInp % 10;
		if (userInp > max) max = userInp;
		userInp = userInp / 10;
	}
	cout << "result: " << max << endl;
}

void taskII()
{
	//dont do yet
}

void taskIII()
{
	//dont do yet
}

void Menu()
{

	int choice;

	while (true) {
		
		cout << "\nSelect task: \n 1 - Task I \n 1 - Task II \n 1 - Task III" << endl;
		cout << "" << endl;

		cin >> choice;

		// cout << "2 - Task II" << endl;
		// cout << "3 - Task III" << endl;
		// cout << "4 - Task IV" << endl;
		// cout << "5 - Task V" << endl;
		// cout << "6 - Task VI" << endl;
		// cout << "7 - Task VII" << endl;
		// cout << "8 - Task VIII" << endl;
		// cout << "9 - Task IX" << endl;
		// cout << "10 - Task X" << endl;
		switch (choice)
		{
		case 1:
			taskI();
			//case 2:
			//	taskII();
			//case 3:
			//	taskIII();
		}
	}
}

//---------------------------------------

int main()
{
	setlocale(LC_ALL, "ru");
	Menu();
}
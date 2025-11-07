#include <iostream>
#include <string>
#include <locale>
using namespace std;

int main()
{
	/// HI, i need to make my taskes (。_。) 
	Menu();
}

void Menu() 
{

	int choice;

	while (true) {

	}
	cout << "Select task: \n 1 - Task I" << endl;
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
	}
}

void taskI() 
{

	int userInp, max = 0;
	div_t result;

	cout << "Enter num: " << endl;
	cin >> userInp;

	while (userInp != max) {
		result = div(userInp, 2);

		userInp = result.quot;
		cout << "chasnoe: " << result.quot << endl;
	}
	cout << "lol: " << userInp << endl;
	cout << "ostatok: " << result.rem << endl;
}
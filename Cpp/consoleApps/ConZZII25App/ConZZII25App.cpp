#include <iostream>
using namespace std;

void TaskI() 
{

	
}

int main()
{
	srand(time(0));

	int userChoice = 0;

	while (true)
	{

		cout << "Choice task: " << endl;
		cout << " 1 - task I" << endl;
		cout << " 2 - task II" << endl;
		cout << " 3 - task III" << endl;
		cout << " 4 - task IV" << endl;
		cout << " 5 - task V" << endl;
		cout << " 0- exit" << endl;

		cin >> userChoice;

		switch (userChoice) {
		case 1:  TaskI(); break;
		//case 2:  TaskII(); break;
		//case 3:  TaskIII(); break;
		//case 4:  TaskIV(); break;
		//case 5:  TaskV(); break;
		default:
			cout << "No such task. Please try again." << endl;
			break;
		}
	}

}

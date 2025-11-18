#include <iostream>
#include <random>
using namespace std;

void TaskI() 
{


}


int main()
{
	int userChoice = 0;

	srand(time(0));

	while (true)
	{

		cout << "Choice task: " << endl;
		cout << " 1 - task I" << endl;
		cout << " 2 - task II" << endl;
		cout << " 3 - task III" << endl;
		cout << " 4 - task IV" << endl;
		cout << " 5 - task V" << endl;
		cout << " 6 - task VI" << endl;
		cout << " 7 - task VII" << endl;
		cout << " 8 - task VIII" << endl;
		cout << " 9 - task IX" << endl;
		cout << " 10- task X" << endl;
		cout << " 0- exit" << endl;

		cin >> userChoice;

	switch (userChoice) {
	case 1:  TaskI(); break;
	//case 2:  TaskII(); break;
	//case 3:  TaskIII(); break;
	//case 4:  TaskIV(); break;
	//case 5:  TaskV(); break;
	//case 6:  TaskVI(); break;
	//case 7:  TaskVII(); break;
	//case 8:  TaskVIII(); break;
	//case 9:  TaskIX(); break;
	//case 10: TaskX(); break;
	case 0: break;
	default:
		cout << "No such task. Please try again." << endl;
		break;
	}
}
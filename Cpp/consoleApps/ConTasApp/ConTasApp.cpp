#include <iostream>
#include <vector>
using namespace std;

void TaskI() 
{
	srand(time(0));
	int i, randNum;
	vector<int> v0(100);
	
	for (i = 0; i <= v0.size(); i++) {
		v0[i] = rand() % (100 - 1 + 1);
	}
	
	if (v0.empty()) {
		for (i = 0; i <= v0.size(); i++) {
			cout << v0[i] << endl;
		}
	}

}

void TaskII() 
{
	int i, userInp;
	vector<int> v0{ 
		1, 2, 3, 
		4, 5, 6, 
		7, 8, 9, 
		0};

	cout << "Enter num: " << endl;
	cin >> userInp;

	for (i = 0; i < v0.size(); i++) {
		if (userInp == v0[i]) {
			cout << "number id in vector : " << i << endl;
			break;
		}
	}
	cout << -1 << endl;

}

void TaskIII() 
{
	int i, userInp;
	vector<int> v0{
		1, 2, 3,
		4, 5, 6,
		7, 8, 9,
		0 };

	cout << "Enter num: " << endl;
	cin >> userInp;

	
}

int main()
{
	int userInp=0;
	
	cout << "Choice task: \n 1- task \n 2- task \n 0- exit" << endl;
	cin >> userInp;

	switch (userInp)
	{
	case 1:
		cout << "Starting task 1" << endl;
		TaskI();
		break;
	case 2:
		TaskII();
		break;
	case 3:
		TaskIII();
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	case 10:
		break;
	case 0:
		break;
	}
}

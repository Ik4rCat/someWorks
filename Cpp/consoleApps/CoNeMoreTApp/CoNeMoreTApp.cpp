#include <iostream>
using namespace std;

void TaskI()
{
	int x, y;
	int* px = &x;
	int* py = &y;

	cout << "Enter first number: " << endl;
	cin >> *px;
	cout << "Enter second number: " << endl;
	cin >> *py;

	if (*py > *px) {
		cout << "The greatest number is \n Address: " << py << "\n Value: " << *py << endl;
	}
	else
	{
		cout << "The greatest number is \n Address: " << px << "\n Value: " << *py << endl;
	}
}

void TaskII()
{
	int x;
	int* px = &x;

	cout << "Enter number: " << endl;
	cin >> x;

	if (*px < 0) {
		cout << "Your number - evil\n address: " << px << "\n Value: " << *px << endl;
	}
	else if (*px > 0) {
		cout << "Your number - friendly\n address: " << px << "\n Value: " << *px << endl;
	}
	else if (*px == 0) {
		cout << "Your number = 0\n address: " << px << "\n Value: " << *px << endl;
	}
}

void TaskIII()
{
	int x, y, rs;
	int* px = &x;
	int* py = &y;

	cout << "Enter first number: " << endl;
	cin >> *px;
	cout << "Enter second number: " << endl;
	cin >> *py;

	cout << "On Start task:\n first: " << *px << "\n second: " << *py << endl;

	rs = rand() % 1 + 0;
	if (rs == 1) {
		*px == *py;
		cout << "On end task:\n first: " << *px << "\n second: " << *py << endl;
	}
	else {
		*py == *px;
		cout << "On end task:\n first: " << *px << "\n second: " << *py << endl;
	}

}

void TaskIV()
{
	cout << "work in progress (task skiped)" << endl;
}

void TaskV()
{
	int mass[15]{};
	int i, x, sum = 0;
	int* px = &x;
	int* psum = &sum;

	for (i = 0; i < size(mass); i++) {
		mass[i] = rand() % 100 + 0;
	}

	for (i = 0; i < size(mass); i++) {
		*psum += mass[i];
	}

	cout << "Summ = " << *psum << "\n adress: " << psum << endl;
}

int main()
{
	srand(time(0));

	int usrInp;

	while (true) {
		cout << "\nChoice task:" << endl;
		cout << " task1 - 1" << endl;
		cout << " task2 - 2" << endl;
		cout << " task3 - 3" << endl;
		cout << " task4 - 4" << endl;
		cout << " task5 - 5" << endl;
		cout << " exit - 0" << endl;

		cin >> usrInp;
		cout << endl;

		switch (usrInp)
		{
		case 1: TaskI(); break;
		case 2: TaskII(); break;
		case 3: TaskIII(); break;
		case 4: TaskIV(); break;
		case 5: TaskV(); break;
		case 0: return 0;
		default:
			cout << "\nWe dont have task like this, try again" << endl;
			break;
		}

	}

}
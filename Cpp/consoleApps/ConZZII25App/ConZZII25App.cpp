#include <iostream>
#include <vector>
using namespace std;

void TaskI_I() 
{
	int i, q, sum = 0, zsum = 0, fsum = 0, ssum = 0, frsum = 0,fosum = 0,fisum = 0;
	const int y = 5, x = 6; 
	int matrix[x][y];
	static int mas[x]{};

	int data[x];


	for (i = 0; i < x; i++) {
		for (q = 0; q < y; q++) {
			 matrix[i][q]= i+q;
		}
	}

	for (i = 0; i < x; i++) {
		cout << "Write some nums for vector: ";
		cin >> data[i];
	}


	cout << "\nYour matrix: " << endl;
	for (i = 0; i < x; i++) {
		for (q = 0; q < y; q++) {
			cout << matrix[i][q] << "\t";
		}
		cout << endl;
	}

	cout << "Your masive: " << endl;
	for (i = 0; i < x; i++) {
			cout << data[i] << "  ";

	}
	
	for (i = 0; i < x; i++) {
		for (q = 0; q < y; q++) {
			sum *= matrix[i][q];
		}
	}

	//строка (массив * строку матрицы)

	for (i = 0; i < size(data); i++) {
		switch (i)
		{
		case 0:
			zsum *= data[i];
		case 1:
			fsum *= data[i];
		case 2: 
			ssum *= data[i];
		case 3: 
			frsum *= data[i];
		case 4: 
			fosum *= data[i];
		case 5:
			fisum *= data[i];
		}
	}


}

void TaskI_II()
{
	int i;
	const int x = 5, y = 5;
	int matrix[y][x];
	int** mas[x]{};



}

void TaskI_III() 
{
	int i;
	const int x = 5, y = 5;
	int matrix[y][x];
	int** mas[x]{};



}

int main()
{
	srand(time(0));

	int userChoice = 0;

	while (true)
	{

		cout << "\nChoice task: " << endl;
		cout << " 1 - task I.I" << endl;
		cout << " 2 - task I.II" << endl;
		cout << " 3 - task I.III" << endl;
		cout << " 0- exit" << endl;

		cin >> userChoice;

		switch (userChoice) {
		case 1:  TaskI_I(); break;
		case 2:  TaskI_II(); break;
		case 3:  TaskI_III(); break;
		case 0: return 0;
		default:
			cout << "No such task. Please try again." << endl;
			break;
		}
	}

}

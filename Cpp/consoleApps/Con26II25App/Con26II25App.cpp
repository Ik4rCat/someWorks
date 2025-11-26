#include <iostream>
using namespace std;


void TaskI() 
{
	int i=0,j=0,snp=0;
	
	while (true) {
		cout << "Enter num" << endl;
		cin >> snp;
		cout << endl;

		if (snp < 100) {
			break;
		}
		cout << "Your num bigger 100, try again" << endl;
	}

	double** mas = new double* [snp];


	for (i = 0;i < snp; i++) {
		mas[i] = new double[snp];

		for (int j = 0; j < snp; j++) {
		

			switch (abs(i - j)) {
			case 0:
				mas[i][j] = 0;
				break;
			case 1:
				mas[i][j] = 1;
				break;
			case 2:
				mas[i][j] = 2;
				break;
			case 3:
				mas[i][j] = 3;
				break;
			case 4:
				mas[i][j] = 4;
				break;
			case 5:
				mas[i][j] = 5;
				break;
			}

			//if (abs(i-j)==0) {
			//	mas[i][j] = 0;
			//	break;
			//}
			//else if (abs(i - j) == 1) {
			//	mas[i][j] = 1;
			//	break;
			//}
			//else if (abs(i - j) == 2) {
			//	mas[i][j] = 2;
			//	break;
			//}
			//else if (abs(i - j) == 3) {
			//	mas[i][j] = 3;
			//	break;
			//}
			//else if (abs(i - j) == 4) {
			//	mas[i][j] = 4;
			//	break;
			//}
			//else if (abs(i - j) == 5) {
			//	mas[i][j] = 5;
			//	break;
			//}
			cout << mas[i][j] << "\t";

		}

		cout << endl;

	}

}

void TaskII() {
	int i, j, srpX, srpY, srp;
	const int x = 1, y = 1;

	while (true) {
		cout << "Enter X for masive: " << endl;
		cin >> srpX;

		cout << "Enter Y for masive: " << endl;
		cin >> srpY;

		if (srpX < 100 || srpY < 100) {
			break;
		}
		cout << "\nur num bigger 100? try again" << endl;
	}

	double** mas = new double* [srpY];

	for (i = 0; i < srpY; i++) {
		mas[i] = new double[srpX]; 
	}

	for (i = 0; i < srpY; i++) {

		for (j = 0; j < srpY; i++) {
			mas[i][j] = rand()% 100;
		}
		cout << mas[i][j] << "\t";
	}


}

int main()
{
	srand(time(0));
	int userChoice = 0;

	while (true)
	{
		cout << "\nChoice task: " << endl;
		cout << " 1 - task I" << endl;
		cout << " 2 - task II" << endl;
		//cout << " 3 - task III" << endl;
		//cout << " 4 - task IV" << endl;
		//cout << " 5 - task V" << endl;
		cout << "0 - exit" << endl;


		cin >> userChoice;

		if (userChoice == 0) {
			break;
		}

		switch (userChoice) {
		case 1:  TaskI(); break;
		case 2:  TaskII(); break;
		//case 3:  TaskIII(); break;
		//case 4:  TaskIV(); break;
		//case 5:  TaskV(); break;
		default:
			cout << "No such task. Please try again." << endl;
			break;
		}
	}
}

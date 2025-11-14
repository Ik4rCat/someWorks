#include <iostream>
#include <list>
using namespace std;


void taskI()
{
	int i, q, fromMasmin=0, fromMasmax=0, masIdmin=0, masIdmax=0;
	int mas[100];

	srand(time(0));

	for (i = 0; i < size(mas);i++) {
		mas[i] = rand() % (100 - 1 + 1) + 1;;
		cout << mas[i] << endl;
	}

	for (i = 0; i <=size(mas);i++) {
		if (i == 0) {
			masIdmin = i;
			fromMasmin = mas[i];
		}
		if (i == size(mas)) {
			masIdmax = i;
			fromMasmax = mas[i-1];
		}
	}

	cout << "max from mass: \n id: " << masIdmax << "\n num: " << fromMasmax << endl;
	cout << "min from mass: \n id: " << masIdmin << "\n num: " << fromMasmin << endl;

}

int main()
{
	int userInp = 0;

	cout << "Choice task: \n 1- task I \n 2- task II \n 0- exit" << endl;
	cin >> userInp;

	switch (userInp)
	{
	case 1:
		taskI();

		break;
	case 2:

		break;
	case 3:
		break;
	case 0:
		break;
	}
}
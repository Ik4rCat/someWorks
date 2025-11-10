#include <iostream>
#include <string>
#include <locale>
using namespace std;

/// HI, i need to make my taskes one more time lol ^_____^


int main()
{
	string userInp;
	const int maxNum = 10;
	int usChoice;
	int train[maxNum];

	cout << "maxNum of masiv: " << maxNum << endl;

	for (int i = 0; i < maxNum; i++ ) {
		cout << "Enter number: " << endl;
		cin >> train[i];
	}
	
	cout << "Wana see nums? \n 1 - yes \n 2 - no, exit program\n";
	cin >> usChoice;
	
	switch (usChoice)
	{
		case 1:
			cout << "Here you go: \n";
			for (int q = 0; q < maxNum; q++) {
				cout << "\n" << train[q] << endl;
			}
			break;
		
		case 2:
			break;
	}



}
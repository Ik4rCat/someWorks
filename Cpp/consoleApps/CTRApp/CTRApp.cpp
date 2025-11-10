#include <iostream>
#include <string>
#include <locale>
using namespace std;

/// HI, i need to make my taskes one more time lol ^_____^


void BubbleSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				// swap arr[j] and arr[j+1]
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


int main()
{
	string userInp;
	const int maxNum = 10;
	int usChoice, sumRes = 0;
	int train[maxNum];

	cout << "maxNum of masiv: " << maxNum << endl;

	for (int i = 0; i <= maxNum; i++ ) {
		cout << "Enter number: " << endl;
		cin >> train[i];
		if (train[i] < 0) sumRes += train[i];
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
			cout << "Sum of evil nums is: " << sumRes <<endl;
			break;
		
		case 2:
			break;
	}



}
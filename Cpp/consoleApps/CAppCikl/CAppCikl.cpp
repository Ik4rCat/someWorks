#include <iostream>
#include <string>
using namespace std;

int main() 
{
	/// HI, here is CAppCikl.cpp
	/// I testing for loops in C++ ^o^
	/// enjoy it!

	int userChoice, userInp;

	cout << "Write number u like: \n 1) friendly numbers \n 2) evil numbers \n 3) * table" << endl;
	cin >> userChoice;

	if (userChoice == 1) {
				cout << "Write number u like: " << endl;
		cin >> userInp;
		for (int i = 0; userInp >= i; i++) {
			int ipp = i + 2;
			cout << "\n" << i << " " << i + 1 << " " << ipp << endl;
			i = ipp;
		}
		return 0;
	}
	else if (userChoice == 2) {
		cout << "Write number u like: " << endl;
		cin >> userInp;

		for (int i = -10; userInp >= i; i++) {
			int ipp = i + 2;
			cout << "\n" << i << " " << i + 1 << " " << ipp << endl;
			i = ipp;
		}
	}
	else if (userChoice == 3) {

	}

}
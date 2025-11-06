#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() 
{
	/// HI, here is CAppCikl.cpp
	/// I testing for loops in C++ ^o^
	/// enjoy it!

	int userChoice, userInp, x;
	int result = 0;

	list<int> numsList = {};
	
	while (true)
	{
		cout <<"\nWrite number u like : \n 1) friendly numbers \n 2) evil numbers \n 3)* table \n 4) nums game" << endl;
		cin >> userChoice;

		switch (userChoice) {
		case 1:
			cout << "Write number u like: " << endl;
			cin >> userInp;
			for (int i = 0; userInp >= i; i++) {
				int ipp = i + 2;
				cout << "\n" << i << " " << i + 1 << " " << ipp << endl;
				i = ipp;
			}
			break;

		case 2:
			cout << "Write number u like: " << endl;
			cin >> userInp;

			for (int i = -10; userInp >= i; i++) {
				int ipp = i + 2;
				cout << "\n" << i << " " << i + 1 << " " << ipp << endl;
				i = ipp;
			}
			break;

		case 3:
			for (int i = 1; i <= 10; ++i) {
				for (int j = 1; j <= 10; ++j) {
					int result = i * j;
					cout << i << " * " << j << " =  " << result << "\t";
				}
				cout << endl;
			}
		case 4:
			while (true)
			{
				cout << "Write num" << endl;
				cin >> x;

				if (x == 0) break;
				result = result + x;


				//if (x != 0) {
				//	numsList.push_back(x);
				//}
				//else {
				//	for (int i=0; i < numsList.size(); i++) {
				//		result = numsList[i] + result;
				//	}
				//}

			}
			cout << "Result is: " << result << endl;
		}
	}
}
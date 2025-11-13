#include <iostream>
#include <string>
using namespace std;


void Box2d(int n, int k) 
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			if (i == 0 || i == n - 1 || j == 0 || j == k - 1) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
}

long long factorialTaskII(int n) {
	if (n == 0) {
		return 1;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		long long result = 1;
		for (int i = 2; i <= n; ++i) {
			result *= i;
		}
		return result;
	}
}

int main()
{
	int userInp = 0;

	cout << "Choice task: \n 1- task I \n 2- task II \n 0- exit" << endl;
	cin >> userInp;

	switch (userInp)
	{
	case 1:
		int w, h;

		cout << "Enter width: ";
		cin >> w;

		cout << "Enter height: ";
		cin >> h;

		if (w < 0 || h < 0) {
			cout << "bro u cant do this" << endl;
			return 0;
		}
		Box2d(h,w);

		break;
	case 2:
		int num;
		cout << "Enter num: ";
		cin >> num;

		if (num < 0) {
			cout << "Bad enter, u need evil num " << endl;
		}
		else {
			long long fact = factorialTaskII(num);
			cout << "num factorial " << num << " = " << fact << endl;
		}
		break;
	case 3:
		break;
	case 0:
		break;
	}

}
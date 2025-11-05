#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	///	HI! WELCOME TO CONSOLE APP BRUH TESTS
	/// Here some tests for C++ code on my college cpp lessons.


	// Seed the random number generator
	int start = 1;
	int end = 30;
	int x = rand() % (end - start + 1) + start; // lol? Why it works like this (。_。)

	// Just a test variables
	int x = 42;
	int y = 13;
	int z = 7;

	//cout << "Our random number: " << x << endl;
	
	cout << "The number x is: " << x << endl;
	cout << "The number x is: " << y << endl;
	cout << "The number x is: " << z << endl;

	// Test switch statement
	switch (true) {
	case 42:
		cout << "The number is even." << endl;
		break;

	default:
		cout << "The number is odd." << endl; // ODD - new horror Kadsima game :D or how he name it ...
		break;
	}
	
	// Test math functions
	cout << fabs(y) << endl;
	cout << abs(z) << endl;
	cout << sqrt(x) << endl;
	cout << exp(x) << endl;
	cout << log(x) << endl;
	cout << log10(x) << endl;
	cout << sin(x) << endl;
	cout << cos(x) << endl;
	cout << tan(x) << endl;
	cout << atan(x) << endl;
	double angle = 0.5;
	cout << asin(angle) << endl;
	cout << acos(angle) << endl;
	cout << sinh(x) << endl;
	cout << cosh(x) << endl;

}

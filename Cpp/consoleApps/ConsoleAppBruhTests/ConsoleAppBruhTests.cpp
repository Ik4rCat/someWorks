#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	///	HI! WELCOME TO CONSOLE APP BRUH TESTS
	/// Here some tests for C++ code on my college cpp lessons.


	// -the random number generator-
	int start = 1;
	int end = 30;
	int x = rand() % (end - start + 1) + start; // lol? Why it works like this (。_。)

	// -Just a test variables-
	int x = 42;
	int y = 13;
	int z = 7;

	//cout << "Our random number: " << x << endl;
	
	cout << "The number x is: " << x << endl;
	cout << "The number x is: " << y << endl;
	cout << "The number x is: " << z << endl;

	// -Test switch statement-
	switch (true) {
	case 42:
		cout << "The number is even." << endl;
		break;

	default:
		cout << "The number is odd." << endl; // ODD - new horror Kadsima game :D or how he name it ...
		break;
	}
	
	// -Test math functions-

	// fab
	cout << fabs(y) << endl;
	
	// abs
	cout << abs(z) << endl;

	// sqrt 
	cout << sqrt(x) << endl;

	// exp
	cout << exp(x) << endl;

	// log
	cout << log(x) << endl;

	// log10
	cout << log10(x) << endl;

	// sin
	cout << sin(x) << endl;

	// cos
	cout << cos(x) << endl;

	// tan
	cout << tan(x) << endl;

	//atan
	cout << atan(x) << endl;

	// dbl. angle
	double angle = 0.5;

	// asin
	cout << asin(angle) << endl;

	// acos
	cout << acos(angle) << endl;

	// sinh
	cout << sinh(x) << endl;

	//cosh
	cout << cosh(x) << endl;

}

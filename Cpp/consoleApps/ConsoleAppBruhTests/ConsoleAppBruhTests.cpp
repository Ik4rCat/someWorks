#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	///	HI! WELCOME TO CONSOLE APP BRUH TESTS
	/// Here some tests for C++ code on my college cpp lessons.

	// Ru: генератор случайных чисел | Eng: random number generator
	int start = 1;
	int end = 30;
	int u = rand() % (end - start + 1) + start; // Ru: формула для диапазона [start, end] | Eng: formula for range [start, end]

	// Ru: тестовые переменные | Eng: test variables
	int x = 42;
	int y = 13;
	int z = 7;

	cout << "The number x is: " << x << endl;
	cout << "The number x is: " << y << endl;  // Ru: ВНИМАНИЕ: выводится y, но текст говорит "x" | Eng: ATTENTION: outputting y but text says "x"
	cout << "The number x is: " << z << endl;  // Ru: аналогичная ошибка в тексте | Eng: similar text error

	// Ru: тест оператора switch | Eng: test switch statement
	switch (true) {  // Ru: ВНИМАНИЕ: условие всегда true, но case проверяет значения | Eng: ATTENTION: condition always true but cases check values
	case 42:  // Ru: этот case никогда не выполнится, т.к. 42 != true | Eng: this case will never execute because 42 != true
		cout << "The number is even." << endl;
		break;

	default:  // Ru: всегда выполняется default ветка | Eng: default branch always executes
		cout << "The number is odd." << endl;
		break;
	}
	
	// Ru: тестирование математических функций | Eng: testing mathematical functions

	// Ru: модуль числа (float/double) | Eng: absolute value (float/double)
	cout << fabs(y) << endl;
	
	// Ru: модуль числа (int) | Eng: absolute value (int)
	cout << abs(z) << endl;

	// Ru: квадратный корень | Eng: square root
	cout << sqrt(x) << endl;

	// Ru: экспонента (e^x) | Eng: exponent (e^x)
	cout << exp(x) << endl;

	// Ru: натуральный логарифм (ln) | Eng: natural logarithm (ln)
	cout << log(x) << endl;

	// Ru: десятичный логарифм | Eng: base-10 logarithm
	cout << log10(x) << endl;

	// Ru: синус угла в радианах | Eng: sine of angle in radians
	cout << sin(x) << endl;

	// Ru: косинус угла в радианах | Eng: cosine of angle in radians
	cout << cos(x) << endl;

	// Ru: тангенс угла в радианах | Eng: tangent of angle in radians
	cout << tan(x) << endl;

	// Ru: арктангенс (возвращает угол в радианах) | Eng: arctangent (returns angle in radians)
	cout << atan(x) << endl;

	// Ru: угол для обратных тригонометрических функций | Eng: angle for inverse trigonometric functions
	double angle = 0.5;

	// Ru: арксинус | Eng: arcsine
	cout << asin(angle) << endl;

	// Ru: арккосинус | Eng: arccosine
	cout << acos(angle) << endl;

	// Ru: гиперболический синус | Eng: hyperbolic sine
	cout << sinh(x) << endl;

	// Ru: гиперболический косинус | Eng: hyperbolic cosine
	cout << cosh(x) << endl;

	return 0;  // Ru: рекомендуется добавить return 0 | Eng: recommended to add return 0
}

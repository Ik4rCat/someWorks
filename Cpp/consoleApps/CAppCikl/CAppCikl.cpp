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

	list<int> numsList = {};  // Ru: создание пустого списка для чисел | Eng: creating empty list for numbers
	
	while (true)  // Ru: бесконечный цикл главного меню | Eng: infinite loop for main menu
	{
		cout <<"\nWrite number u like : \n 1) friendly numbers \n 2) evil numbers \n 3)* table \n 4) nums game" << endl;
		cin >> userChoice;

		switch (userChoice) {  // Ru: выбор операции пользователем | Eng: user operation selection
		case 1:
			cout << "Write number u like: " << endl;
			cin >> userInp;
			// Ru: вывод последовательных троек чисел | Eng: output consecutive number triples
			for (int i = 0; userInp >= i; i++) {
				int ipp = i + 2;
				cout << "\n" << i << " " << i + 1 << " " << ipp << endl;
				i = ipp;  // Ru: пропуск двух чисел в итерации | Eng: skipping two numbers in iteration
			}
			break;

		case 2:
			cout << "Write number u like: " << endl;
			cin >> userInp;

			// Ru: аналогично case 1, но с отрицательного старта | Eng: similar to case 1 but starting from negative
			for (int i = -10; userInp >= i; i++) {
				int ipp = i + 2;
				cout << "\n" << i << " " << i + 1 << " " << ipp << endl;
				i = ipp;
			}
			break;

		case 3:
			// Ru: создание таблицы умножения 10x10 | Eng: creating 10x10 multiplication table
			for (int i = 1; i <= 10; ++i) {
				for (int j = 1; j <= 10; ++j) {
					int result = i * j;
					cout << i << " * " << j << " =  " << result << "\t";
				}
				cout << endl;
			}
			// Ru: отсутствует break - выполнение перейдет к case 4 | Eng: missing break - execution will fall through to case 4
		case 4:
			// Ru: вложенный бесконечный цикл для суммирования чисел | Eng: nested infinite loop for number summation
			while (true)
			{
				cout << "Write num" << endl;
				cin >> x;

				if (x == 0) break;  // Ru: выход из внутреннего цикла при вводе 0 | Eng: exit inner loop when input is 0
				result = result + x;  // Ru: накопление суммы введенных чисел | Eng: accumulating sum of entered numbers

				// Ru: закомментированная альтернативная реализация со списком | Eng: commented alternative implementation with list
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

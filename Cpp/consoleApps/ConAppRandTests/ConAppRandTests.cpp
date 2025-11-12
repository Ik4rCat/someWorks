#include <iostream>
#include <string>
#include <ctime>
#include <locale>

using namespace std;

int main()
{
	/// HI, Here i testing random in cpp on my cpp college lessons ＼（〇_ｏ）／
	/// I'm interested in how it works in Unreal engine (。_。)
	setlocale(LC_ALL, "ru");  // Ru: установка русской локали для вывода | Eng: setting Russian locale for output

	int x, y, i;

	// Ru: ввод диапазона для случайного числа | Eng: input range for random number
	cout << "Start num" << endl;
	cin >> x;
	cout << "End num" << endl;
	cin >> y;

	srand(time(0));  // Ru: инициализация генератора случайных чисел текущим временем | Eng: initialize random generator with current time
	i = rand() % (y - x + 1) + x;  // Ru: генерация числа в заданном диапазоне [x, y] | Eng: generate number in specified range [x, y]
	
	cout << "your random num = " << i << "\n" << endl;

	// Ru: случайный выбор управляющего символа | Eng: random selection of control character
	switch (rand() % (10 - 1+1)+1) {  // Ru: генерация числа от 1 до 10 | Eng: generate number from 1 to 10
	case 0:
		cout << "Возрат каретки в начало строки " << "\r" << endl;  // Ru: возврат каретки | Eng: carriage return
		break;
	case 1:
		cout << "Новая строка " << "\n" << endl;  // Ru: новая строка | Eng: new line
		break;
	case 2:
		cout << "Горизонтальная табуляция " << "\t" << endl;  // Ru: горизонтальная табуляция | Eng: horizontal tab
		break;
	case 3:
		cout << "Вертикальная табуляция " << "\v" << endl;  // Ru: вертикальная табуляция | Eng: vertical tab
		break;
	case 4:
		cout << "двойные кавычки " << "\1" << endl;  // Ru: ВНИМАНИЕ: \1 это не двойные кавычки | Eng: ATTENTION: \1 is not double quotes
		break;
	case 5:
		cout << "Апостров " << "\'" << endl;  // Ru: апостроф | Eng: apostrophe
		break;
	case 6:
		cout << "обратный слеш " << "\\" << endl;  // Ru: обратный слеш | Eng: backslash
		break;
	case 7:
		cout << "Нулевой символ " << "\0" << endl;  // Ru: нулевой символ (не будет виден) | Eng: null character (will not be visible)
		break;
	case 8:
		cout << "Знак вопроса " << "\?" << endl;  // Ru: знак вопроса | Eng: question mark
		break;
	case 9:
		cout << "Сигнал бипера (спикера) компьютера " << "\a" << endl;  // Ru: звуковой сигнал | Eng: audible bell
		break;
	}

	// Ru: вывод нескольких случайных чисел | Eng: output several random numbers
	cout << "\nSome random nums \n" << endl;
	cout << "random num first = " << rand() % 100 + 1 << endl;  // Ru: число от 1 до 100 | Eng: number from 1 to 100
	cout << "random num second = " << rand()  << endl;  // Ru: случайное число в полном диапазоне | Eng: random number in full range
	cout << "random num third = " << rand()  << endl;  // Ru: следующее случайное число | Eng: next random number

	return 0;  // Ru: завершение программы | Eng: program termination
}
